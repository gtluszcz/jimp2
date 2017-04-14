//
// Created by Dariusz Czajkowski on 14/04/2017.
//

#include "Point3d.h"
#include <iostream>

using ::std::cout;
using ::std::endl;

int main() {
    /**
     * Order of constructors and destructors is:
     * 1. 'Point' class - parameter constructor - point3d object
     * 2. 'Point3d' class - parameter constructor - point3d object
     * 3. 'Point' class - parameter constructor - point2d object
     * 4. 'Point' class - destructor - point3d object
     * 5. 'Point3d' class - destructor - point3d object
     * 6. 'Point' class - destructor - point2d object
     */
    Point3d point3d(0, 0, 1);
    Point point2d(1, 1);

    /**
     * The distance has been calculated as if the third dimension didn't exist.
     * The 'Point' type-hint allowed the 'Point3d' object to be passed in as
     * it extends the required 'Point' class.
     */
    cout << point2d.Distance(point3d) << endl;


    /**
     * The cout doesn't work as the operator<< has not been defined anywhere.
     */
    Point3d newPoint3d(1, 2, 3);
    // cout << newPoint3d << endl;

    return 0;
}