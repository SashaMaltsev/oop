#include "Figure.cpp"


template<typename T>
class Rhomb : public Figure<T> {
public:
    Rhomb();
    Rhomb(const Rhomb& other);
    Rhomb(Rhomb&& other);
    Rhomb(const std::initializer_list<Point<T>>& init);
    ~Rhomb() = default;

    Rhomb& operator=(const Rhomb& other) = default;
    Rhomb& operator=(Rhomb&& other) = default; 

    operator double() const override;


    double Square() const override;
};

template<typename T>
Rhomb<T>::Rhomb() : Figure<T>() {
    this->name_ = "Rhomb";
}

template<typename T>
Rhomb<T>::Rhomb(const Rhomb& other) : Figure<T>(other) {
    this->name_ = "Rhomb";
}

template<typename T>
Rhomb<T>::Rhomb(Rhomb&& other) : Figure<T>(other) {
    this->name_ = "Rhomb";
    other.name_ = "";
}

template<typename T>
Rhomb<T>::Rhomb(const std::initializer_list<Point<T>>& init) : Figure<T>(init) {
    this->name_ = "Rhomb";
}

template <typename T>
Rhomb<T>::operator double() const {
    return this->Square();
}

template <typename T>
double Rhomb<T>::Square() const {
    double a = this->Length(this->vertices_[0], this->vertices_[2]);
    return (this->Length(this->vertices_[0], this->vertices_[2]) * this->Length(this->vertices_[1], this->vertices_[3])) / 2.0;
}
