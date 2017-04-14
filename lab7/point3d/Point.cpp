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

double Point::distance(const Point &other) const {
    return sqrt(pow(getX() - other.getX(), 2) + pow(getY() - other.getY(), 2));
}

void Point::toString(ostream * out) const {
    (*out) << "(" << getX() << ";" << getY() << ")";
}

double Point::getX() const {
    return x_;
}

double Point::getY() const {
    return y_;
}

void Point::setX(double x) {
    x_ = x;
}

void Point::setY(double y) {
    y_ = y;
}


