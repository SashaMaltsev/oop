#include "Figure.cpp"


class Trapezoid : public Figure {
public:
    Trapezoid();
    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other);
    Trapezoid(const std::initializer_list<Point>& init);
    ~Trapezoid() = default;

    Trapezoid& operator=(const Trapezoid& other) = default;
    Trapezoid& operator=(Trapezoid&& other) = default;

    double Square() override;
};

Trapezoid::Trapezoid(const Trapezoid& other) : Figure(other) {
    this->name_ = "Trapezoid";
}

Trapezoid::Trapezoid(Trapezoid&& other) : Figure(other) {
    this->name_ = "Trapezoid";
    other.name_ = "";
}

Trapezoid::Trapezoid() : Figure() {
    this->name_ = "Trapezoid";
}

Trapezoid::Trapezoid(const std::initializer_list<Point>& init) : Figure(init) {
    this->name_ = "Trapezoid";
}

double Trapezoid::Square() {
    double a = this->Length(this->vertices_[1], this->vertices_[2]); 
    double b = this->Length(this->vertices_[0], this->vertices_[3]);
    double h = sqrt(pow(this->Length(this->vertices_[0], this->vertices_[1]), 2) - pow(this->vertices_[0].x - this->vertices_[1].x, 2));
    return (a + b) * h / 2.0;
}
