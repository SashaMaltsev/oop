#pragma once

#include <iostream>
#include <vector>
#include <initializer_list>

#include "Point.cpp"


template<typename T> 
class Figure {
public:

    Figure() = default;
    Figure(const Figure& other);
    Figure(Figure&& other);
    Figure(const std::initializer_list<Point<T>>& init);
    virtual ~Figure() = default;

    Point<T> Center();

    virtual double Square() const = 0;
    virtual operator double() const = 0;


    template<typename Y> 
    friend std::ostream &operator<<(std::ostream& out, Figure<Y>& figure);

    template<typename Y> 
    friend std::istream &operator>>(std::istream& in, Figure<Y>& figure);

    virtual bool operator== (const Figure& other) const;
    virtual Figure& operator=(const Figure& other);
    virtual Figure& operator=(Figure&& other);

    std::string GetName();

protected:
    std::vector<Point<T>> vertices_;
    std::string name_;

    double Length(const Point<T>& p1, const Point<T>& p2) const;
};

template <typename T>
Figure<T>::Figure(const std::initializer_list<Point<T>>& init) : vertices_(init), name_() {
}

template <typename T>
Figure<T>::Figure(Figure<T>&& other) : vertices_(other.vertices_), name_(other.name_) {
    other.vertices_ = {};
    other.name_ = "";
}

template <typename T>
Figure<T>::Figure(const Figure<T>& other) : vertices_(other.vertices_), name_(other.name_) {
}

template <typename T>
Point<T> Figure<T>::Center() {

    double x0 = 0; 
    double y0 = 0;

    for (Point<T>& point : this->vertices_) {
        x0 += point.x;
        y0 += point.y;
    }

    return Point(x0 / this->vertices_.size(), y0 / this->vertices_.size());
}

template <typename T>
double Figure<T>::Length(const Point<T>& p1, const Point<T>& p2) const {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

template <typename T>
std::ostream& operator<<(std::ostream& out, Figure<T>& fig) {
    
    out << fig.name_ << ": { ";

    for (Point<T>& p : fig.vertices_) {
        out << "(" << p.x << ", " << p.y << ") ";
    } out << "}";

    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, Figure<T>& fig) {

    // 10 11 12 12 24;
    double x, y;

    while (in >> x >> y) {
        fig.vertices_.push_back(Point(x, y));
    }
    
    return in;
}

template <typename T>
bool Figure<T>::operator==(const Figure<T>& other) const {

    if (this->vertices_.size() != other.vertices_.size()) return false;

    for (size_t i = 0; i < this->vertices_.size(); ++i) {
        if (this->vertices_[i].x != other.vertices_[i].x) return false;
        if (this->vertices_[i].y != other.vertices_[i].y) return false;
    }

    return true;
}

template <typename T>
Figure<T>& Figure<T>::operator=(const Figure<T>& other) {
    this->name_ = other.name_;
    this->vertices_ = other.vertices_;
    return *this;
}

template <typename T>
Figure<T>& Figure<T>::operator=(Figure<T>&& other) {
    this->name_ = other.name_;
    this->vertices_ = other.vertices_;

    other.name_ = "";
    other.vertices_ = {};

    return *this;
}

template <typename T>
std::string Figure<T>::GetName() {
    return this->name_;
}