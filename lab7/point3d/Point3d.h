//
// Created by Dariusz Czajkowski on 14/04/2017.
//

#ifndef JIMP_EXERCISES_POINT3D_H
#define JIMP_EXERCISES_POINT3D_H

#include "Point.h"

class Point3d : public Point {
protected:
    double z_;

public:
    Point3d();
    Point3d(double x, double y, double z);
    ~Point3d();
    double distance(const Point3d &other) const;
    double getZ() const;
    void setZ(double z);
};


#endif //JIMP_EXERCISES_POINT3D_H
