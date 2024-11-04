#include "Figure.cpp"


template<typename T>
class Pentagon : public Figure<T> {
public:
    Pentagon();
    Pentagon(const Pentagon& other);
    Pentagon(Pentagon&& other);
    Pentagon(const std::initializer_list<Point<T>>& init);
    ~Pentagon() = default;

    Pentagon& operator=(const Pentagon& other) = default;
    Pentagon& operator=(Pentagon&& other) = default; 

    operator double() const override;

    double Square() const override;
};


template<typename T>
Pentagon<T>::Pentagon() : Figure<T>() {
    this->name_ = "Pentagon";
}

template<typename T>
Pentagon<T>::Pentagon(const std::initializer_list<Point<T>>& init) : Figure<T>(init) {
    this->name_ = "Pentagon";
}

template<typename T>
Pentagon<T>::Pentagon(const Pentagon& other) : Figure<T>(other) {
    this->name_ = "Pentagon";
}

template<typename T>
Pentagon<T>::Pentagon(Pentagon&& other) : Figure<T>(other) {
    this->name_ = "Pentagon";
    other.name_ = "";
}

template <typename T>
Pentagon<T>::operator double() const {
    return this->Square();
}

template <typename T>
double Pentagon<T>::Square() const {
    double s = this->Length(this->vertices_[0], this->vertices_[1]);
    return sqrt(25 + 10 * sqrt(5)) * pow(s, 2) / 4;
}
