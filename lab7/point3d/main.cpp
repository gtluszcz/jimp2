//
// Created by Dariusz Czajkowski on 14/04/2017.
//

#include "Point3d.h"
#include <iostream>

using ::std::cout;
using ::std::endl;

int main() {
    Point3d point3d(10, 12, 2);
    Point point2d(3, 5);

    cout << point2d.Distance(point3d) << endl;


    Point3d newPoint3d(1, 2, 3);
    cout << newPoint3d << endl;

    return 0;
}