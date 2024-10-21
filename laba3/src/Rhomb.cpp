#include "Figure.cpp"


class Rhomb : public Figure {
public:
    Rhomb();
    Rhomb(const Rhomb& other);
    Rhomb(Rhomb&& other);
    Rhomb(const std::initializer_list<Point>& init);
    ~Rhomb() = default;

    Rhomb& operator=(const Rhomb& other) = default;
    Rhomb& operator=(Rhomb&& other) = default; 

    double Square() override;
};

Rhomb::Rhomb() : Figure() {
    this->name_ = "Rhomb";
}

Rhomb::Rhomb(const Rhomb& other) : Figure(other) {
    this->name_ = "Rhomb";
}

Rhomb::Rhomb(Rhomb&& other) : Figure(other) {
    this->name_ = "Rhomb";
    other.name_ = "";
}

Rhomb::Rhomb(const std::initializer_list<Point>& init) : Figure(init) {
    this->name_ = "Rhomb";
}

double Rhomb::Square() {
    double a = this->Length(this->vertices_[0], this->vertices_[2]);
    return (this->Length(this->vertices_[0], this->vertices_[2]) * this->Length(this->vertices_[1], this->vertices_[3])) / 2.0;
}
