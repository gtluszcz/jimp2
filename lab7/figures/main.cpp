#include <iostream>
#include "Figures.h"

using namespace std;

int main() {
    /**
     * Exercise 8
     */
    Sphere k(0, 0, 0, 10);

    cout << k.Circle::surface() << endl;
}
