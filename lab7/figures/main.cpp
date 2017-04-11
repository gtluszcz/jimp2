#include <iostream>
#include <math.h>

const double PI = 3.14159265359;

using namespace std;

class Circle {
protected:
    double x;
    double y;
    double r;

public:
    Circle(double _x, double _y, double _r) {
        x = _x;
        y = _y;
        r = _r;
    }

    double surface() {
        return PI * pow(r, 2);
    }
};

class Sphere : public Circle {
protected:
    double z;

public:
    Sphere(double _x, double _y, double _z, double _r) : Circle(_x, _y, _r) {
        z = _z;
    }

    double surface() {
        return 4 * PI * pow(r, 2);
    }
};

int main() {
    Sphere k(0, 0, 0, 10);

    cout << k.Circle::surface() << endl;
}
