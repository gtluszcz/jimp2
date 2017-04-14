//
// Created by Dariusz Czajkowski on 14/04/2017.
//

#include "Point3d.h"
#include <iostream>
#include <cmath>

using ::std::pow;
using ::std::sqrt;
using ::std::cout;
using ::std::endl;

Point3d::Point3d():z_(0) {
    cout << "'Point3d' class constructor!" << endl;
}

Point3d::~Point3d() {
    cout << "'Point3d' class destructor!";
    cout << endl;
}

double Point3d::distance(const Point3d &other) const {
    return sqrt(pow(getX() - other.getX(), 2) + pow(getY() - other.getY(), 2) + pow(getZ() - other.getZ(), 2));
}

double Point3d::getZ() const {
    return z_;
}

void Point3d::setZ(double z) {
    z_ = z;
}

Point3d::Point3d(double x, double y, double z) : Point(x, y) {
    cout << "'Point3d' class parameter constructor" << endl;
    z_ = z;
}
