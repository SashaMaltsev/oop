#include <cmath> 

template<typename T>
class Point {
public:
    Point(T x = 0.0, T y = 0.0);

    T x;
    T y;
};


template <typename T>
Point<T>::Point(T x, T y) : x(x), y(y) {
}
