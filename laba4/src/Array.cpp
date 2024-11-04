#pragma once

#include <memory>
#include <initializer_list>

template<typename T, std::size_t N>
class Array {
public:

	Array();                            
	Array(const Array& other);
    Array(const std::initializer_list<T>& init);      
	~Array() = default;

    size_t Size() const;
    T& operator[](size_t i) const;

private:
    std::shared_ptr<T[N]> sp_;
};

template <typename T, std::size_t N>
Array<T, N>::Array() : sp_(std::make_shared<T[N]>()) {
}

template <typename T, std::size_t N>
Array<T, N>::Array(const Array& other) : sp_(std::make_shared<T[N]>()) {
    for (size_t i = 0; i < N; ++i) {
        this->sp_[i] = other[i];
    }
}

template <typename T, std::size_t N>
Array<T, N>::Array(const std::initializer_list<T>& init) : sp_(std::make_shared<T[N]>()) {
	size_t i = 0;
    for (auto it = init.begin(); it != init.end(); ++it) {
		this->sp_[i++] = *it;
	}
}

template <typename T, std::size_t N>
size_t Array<T, N>::Size() const {
    return this->Size();
}

template <typename T, std::size_t N>
T& Array<T, N>::operator[](size_t i) const {
    return this->sp_[i];
}


template<typename T, std::size_t N>
double areaFigInArray(const Array<T, N>& arr) {
    double area = 0;
    for (size_t i = 0; i < N; ++i) {
        area += arr[i].Square();
    }
    return area;
}
