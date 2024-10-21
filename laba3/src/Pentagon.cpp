#include "Figure.cpp"


class Pentagon : public Figure {
public:
    Pentagon();
    Pentagon(const Pentagon& other);
    Pentagon(Pentagon&& other);
    Pentagon(const std::initializer_list<Point>& init);
    ~Pentagon() = default;

    Pentagon& operator=(const Pentagon& other) = default;
    Pentagon& operator=(Pentagon&& other) = default; 

    double Square() override;
};


Pentagon::Pentagon() : Figure() {
    this->name_ = "Pentagon";
}

Pentagon::Pentagon(const std::initializer_list<Point>& init) : Figure(init) {
    this->name_ = "Pentagon";
}

Pentagon::Pentagon(const Pentagon& other) : Figure(other) {
    this->name_ = "Pentagon";
}

Pentagon::Pentagon(Pentagon&& other) : Figure(other) {
    this->name_ = "Pentagon";
    other.name_ = "";
}

double Pentagon::Square() {
    double s = this->Length(this->vertices_[0], this->vertices_[1]);
    return sqrt(25 + 10 * sqrt(5)) * pow(s, 2) / 4;
}




