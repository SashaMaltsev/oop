#pragma once

#include <memory> 

template <typename T, std::size_t POOL_SIZE = 1024UL> 
class PoolAllocator {
public:

    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using void_pointer = void*;
    using const_void_pointer = const void*;
    using difference_type = std::ptrdiff_t;
    using size_type = std::size_t;
    using propagate_on_container_copy_assignment = std::false_type;
    using propagate_on_container_swap = std::false_type;
    using propagate_on_container_move_assignment = std::false_type;
    using is_always_equal = std::false_type;
    template<class Other> struct rebind { using other =  PoolAllocator<Other, POOL_SIZE>; };


    PoolAllocator();
    ~PoolAllocator();

    PoolAllocator(const PoolAllocator& other) = delete;
    PoolAllocator(PoolAllocator&& other) = delete;
    PoolAllocator operator =(const PoolAllocator& other) = delete;
    PoolAllocator operator =(PoolAllocator&& other) = delete;

    pointer allocate(size_t count);
    void deallocate(pointer ptr, size_t);

    template<typename U, typename... Args> inline void construct(U* ptr, const Args&... args) const;
    template<typename U, typename... Args> inline void construct(U* ptr, Args&&... args) const;
    template<typename U> inline void destroy(U* ptr) const;

private:

    struct Node {
        Node* next_ = nullptr;
    };

    pointer data_;
    Node* start_;

    static_assert(!std::is_same_v<value_type, void>);
    static_assert(POOL_SIZE != 0u);
};


template <typename T, std::size_t POOL_SIZE>
PoolAllocator<T, POOL_SIZE>::PoolAllocator() {

    const constexpr std::size_t j = sizeof(value_type) >= 8 ? sizeof(value_type) : 8;

    this->data_ = reinterpret_cast<pointer>(new char[j * POOL_SIZE]);
    this->start_ = new (this->data_) Node();
    auto it = this->start_;

    for (std::size_t i = j; i < j * POOL_SIZE; i += j) {
        it->next_ = new (reinterpret_cast<char*>(this->data_) + i) Node();
        it = it->next_;
    }
}


template <typename T, std::size_t CHUNK_SIZE>
PoolAllocator<T, CHUNK_SIZE>::~PoolAllocator() {
    delete[] reinterpret_cast<char*>(data_);
}


template <typename T, std::size_t POOL_SIZE>
typename PoolAllocator<T, POOL_SIZE>::pointer PoolAllocator<T, POOL_SIZE>::allocate(size_t count) {

    if (this->start_ != nullptr) {
        Node* prev = this->start_;
        this->start_ = this->start_->next_;
        return reinterpret_cast<pointer>(prev);
    } else {
        throw std::exception();  // memory is over
    }
    return nullptr;
}


template <typename T, std::size_t POOL_SIZE>
void PoolAllocator<T, POOL_SIZE>::deallocate(pointer ptr, size_t) {

    new (ptr) Node();

    if (this->start_ == nullptr) {
        this->start_ = reinterpret_cast<Node*>(ptr);
        return;
    }

    Node* it = this->start_; 

    while (it->next_ != nullptr) {
        it = it->next_;
    }

    it->next_ = reinterpret_cast<Node*>(ptr); 
}


template <typename T, std::size_t POOL_SIZE>
template <typename U, typename... Args>
inline void PoolAllocator<T, POOL_SIZE>::construct(U *ptr, const Args& ...args) const {
    new (ptr) U(args...);
}

template <typename T, std::size_t POOL_SIZE>
template <typename U, typename... Args>
inline void PoolAllocator<T, POOL_SIZE>::construct(U *ptr, Args &&...args) const {
    new (ptr) U(std::forward<Args>(args)...);
}

template <typename T, std::size_t POOL_SIZE>
template <typename U>
inline void PoolAllocator<T, POOL_SIZE>::destroy(U *ptr) const {
    if constexpr (std::is_same<U*, void*>::value) {
		free(ptr);
	} else {
		ptr->~U();
	}
}
