//
// Created by Dariusz Czajkowski on 14/04/2017.
//

#ifndef JIMP_EXERCISES_POINT_H
#define JIMP_EXERCISES_POINT_H

#include "Point.h"
#include <ostream>

using ::std::ostream;

class Point {
protected:
    double x_, y_;

public:
    Point();
    Point(double x, double y);
    ~Point();

    void toString(ostream * out) const;
    double distance(const Point &other) const;

    double getX() const;
    double getY() const;

    void setX(double x);
    void setY(double y);
};

#endif //JIMP_EXERCISES_POINT_H
