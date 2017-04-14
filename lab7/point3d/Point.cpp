//
// Created by Dariusz Czajkowski on 14/04/2017.
//

#include <cmath>
#include <iostream>
#include "Point.h"

using ::std::ostream;
using ::std::endl;
using ::std::pow;
using ::std::sqrt;
using ::std::cout;

Point::Point():x_(0),y_(0) {
    cout << "'Point' class constructor!" << endl;
}

Point::Point(double x, double y) {
    cout << "'Point' class parameter constructor" << endl;
    x_ = x;
    y_ = y;
}

Point::~Point() {
    cout << "'Point' class destructor!";
    cout << endl;
}

double Point::Distance(const Point &other) const {
    return sqrt(pow(GetX() - other.GetX(), 2) + pow(GetY() - other.GetY(), 2));
}

void Point::ToString(ostream *out) const {
    (*out) << "(" << GetX() << ";" << GetY() << ")";
}

double Point::GetX() const {
    return x_;
}

double Point::GetY() const {
    return y_;
}

void Point::SetX(double x) {
    x_ = x;
}

void Point::SetY(double y) {
    y_ = y;
}


