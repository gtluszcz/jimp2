/**
 * Exercise 8
 */

#include "Figures.h"

Circle::Circle(double _x, double _y, double _r) {
    x = _x;
    y = _y;
    r = _r;
}

double Circle::surface() {
    return PI * pow(r, 2);
}

Sphere::Sphere(double _x, double _y, double _z, double _r) : Circle(_x, _y, _r) {
    z = _z;
}

double Sphere::surface() {
    return 4 * PI * pow(r, 2);
}