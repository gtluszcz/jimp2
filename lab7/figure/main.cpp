#include <vector>
#include <iostream>

#include "Circle.h"
#include "Square.h"
#include "Triangle.h"

using ::std::vector;
using ::std::cout;
using ::std::endl;

int main() {
    Circle c1;
    Circle c2;
    Circle c3;
    Square s1;
    Square s2;
    Square s3;
    Triangle t1;
    Triangle t2;
    Triangle t3;

    Figure * figures[9];
    figures[0] = &c1;
    figures[1] = &s3;
    figures[2] = &s2;
    figures[3] = &s1;
    figures[4] = &t1;
    figures[5] = &t2;
    figures[6] = &c2;
    figures[7] = &t3;
    figures[8] = &c3;

    for (auto & figure : figures) {
        cout << figure->draw() << endl;
    }

    return 0;
}
