/**
 * Exercise 8
 */

#ifndef JIMP_EXERCISES_FIGURES_H
#define JIMP_EXERCISES_FIGURES_H

#include <math.h>

const double PI = 3.14159265359;

class Circle {
protected:
    double x;
    double y;
    double r;

public:
    Circle(double _x, double _y, double _r);
    double surface();
};

class Sphere : public Circle {
protected:
    double z;

public:
    Sphere(double _x, double _y, double _z, double _r);
    double surface();
};


#endif //JIMP_EXERCISES_FIGURES_H
