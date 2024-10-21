#pragma once

#include <iostream>
#include <vector>
#include <initializer_list>

#include "Point.cpp"


class Figure {
public:

    Figure() = default;
    Figure(const Figure& other);
    Figure(Figure&& other);
    Figure(const std::initializer_list<Point>& init);
    virtual ~Figure() = default;
    
    Point Center();
    virtual double Square() = 0;
    friend std::ostream &operator<<(std::ostream &out, Figure &figure);
    friend std::istream &operator>>(std::istream &in, Figure &figure);

    virtual bool operator== (const Figure& other) const;
    virtual Figure& operator=(const Figure& other);
    virtual Figure& operator=(Figure&& other);

    std::string GetName();

protected:
    std::vector<Point> vertices_;
    std::string name_;

    double Length(const Point &p1, const Point &p2) const;
};

Figure::Figure(const std::initializer_list<Point>& init) : vertices_(init), name_() {
}

Figure::Figure(Figure&& other) : vertices_(other.vertices_), name_(other.name_) {
    other.vertices_ = {};
    other.name_ = "";
}

Figure::Figure(const Figure& other) : vertices_(other.vertices_), name_(other.name_) {
}

Point Figure::Center() {

    double x0 = 0; 
    double y0 = 0;

    for (Point& point : this->vertices_) {
        x0 += point.x;
        y0 += point.y;
    }

    return Point(x0 / this->vertices_.size(), y0 / this->vertices_.size());
}

double Figure::Length(const Point &p1, const Point &p2) const {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

std::ostream& operator<<(std::ostream& out, Figure& fig) {
    
    out << fig.name_ << ": { ";

    for (Point& p : fig.vertices_) {
        out << "(" << p.x << ", " << p.y << ") ";
    } out << "}";

    return out;
}

std::istream& operator>>(std::istream& in, Figure& fig) {

    // 10 11 12 12 24;
    double x, y;

    while (in >> x >> y) {
        fig.vertices_.push_back(Point(x, y));
    }
    
    return in;
}

bool Figure::operator==(const Figure &other) const {

    if (this->vertices_.size() != other.vertices_.size()) return false;

    for (size_t i = 0; i < this->vertices_.size(); ++i) {
        if (this->vertices_[i].x != other.vertices_[i].x) return false;
        if (this->vertices_[i].y != other.vertices_[i].y) return false;
    }

    return true;
}

Figure& Figure::operator=(const Figure& other) {
    this->name_ = other.name_;
    this->vertices_ = other.vertices_;
    return *this;
}

Figure& Figure::operator=(Figure&& other) {
    this->name_ = other.name_;
    this->vertices_ = other.vertices_;

    other.name_ = "";
    other.vertices_ = {};

    return *this;
}

std::string Figure::GetName() {
    return this->name_;
}
