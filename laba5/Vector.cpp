
template <class T, class Allocator = std::allocator<T>>
class Vector{
    private:
        Allocator allocator;
        size_t _size;
        size_t _capacity;
        T* data;

    public:
        Vector() : _size(0), _capacity(0), data(nullptr) {}

        ~Vector() {
            clear();
        }

        void push_back(const T& value) {
            if (_size == _capacity) {
                reserve(_capacity == 0 ? 1 : _capacity * 2);
            }
            data[_size] = value;
            ++_size;
        }

        void pop_back() {
            if (_size > 0) {
                --_size;
            }
        }

        size_t size() const noexcept {
            return _size;
        }

        T& operator[](size_t pos) {
            return data[pos];
        }

        void reserve(size_t new_capacity) {
            if (new_capacity > _capacity) {
                T* new_data;
                T* it;
                
                for (size_t i = 0; i < new_capacity; ++i) {

                    new_data = allocator.allocate(1);

                    if (i < _size)
                        allocator.construct(new_data, data[i]);

                    if (i == 0) 
                        it = new_data;
                }

                for (size_t i = 0; i < _capacity; ++i) {
                    allocator.destroy(data + i);
                    allocator.deallocate(data + i, 1);
                }

                data = it;
                _capacity = new_capacity;
            }
        }

        void clear() {  // не работает если T < 8 байт. нужно использовать тогда константу смещеня 
            for (size_t i = 0; i < _size; ++i) {
                this->allocator.destroy(data + i);
                allocator.deallocate(data + i, 1);
            }
            _size = 0;
        }
};