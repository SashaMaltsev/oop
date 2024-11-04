#include "Figure.cpp"

template<typename T>
class Trapezoid : public Figure<T> {
public:
    Trapezoid();
    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other);
    Trapezoid(const std::initializer_list<Point<T>>& init);
    ~Trapezoid() = default;

    Trapezoid& operator=(const Trapezoid& other) = default;
    Trapezoid& operator=(Trapezoid&& other) = default;

    operator double() const override;

    double Square() const override;
};

template<typename T>
Trapezoid<T>::Trapezoid(const Trapezoid& other) : Figure<T>(other) {
    this->name_ = "Trapezoid";
}

template<typename T>
Trapezoid<T>::Trapezoid(Trapezoid&& other) : Figure<T>(other) {
    this->name_ = "Trapezoid";
    other.name_ = "";
}

template<typename T>
Trapezoid<T>::Trapezoid() : Figure<T>() {
    this->name_ = "Trapezoid";
}

template<typename T>
Trapezoid<T>::Trapezoid(const std::initializer_list<Point<T>>& init) : Figure<T>(init) {
    this->name_ = "Trapezoid";
}

template <typename T>
Trapezoid<T>::operator double() const {
    return this->Square();
}

template <typename T>
double Trapezoid<T>::Square() const {
    double a = this->Length(this->vertices_[1], this->vertices_[2]); 
    double b = this->Length(this->vertices_[0], this->vertices_[3]);
    double h = sqrt(pow(this->Length(this->vertices_[0], this->vertices_[1]), 2) - pow(this->vertices_[0].x - this->vertices_[1].x, 2));
    return (a + b) * h / 2.0;
}
