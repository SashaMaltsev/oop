#include <cmath> 


class Point {
public:
    Point(double x = 0.0, double y = 0.0);

    double x;
    double y;
};

Point::Point(double x, double y) : x(x), y(y) {
}

