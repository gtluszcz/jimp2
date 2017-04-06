//
// Created by Grzegorz on 04.04.2017.
//

#include "Matrix.h"
#include <iostream>

using std::cout;
using std::endl;
using algebra::Matrix;

int main() {
    Matrix m1("[13i65 2.0 3; 7 4 3]");
    Matrix m2(m1);

    cout << "Matrix one is:" << endl;
    m1.Print();
    cout << endl << "Matrix two (same as one) is:" << endl;
    m2.Print();
    cout << endl << "Matrix that is a result of adding two same matrices (one and two) is:" << endl;
    m1.add(m2).Print();

    Matrix m3("[1 2 3; 4 5 6]");
    cout << endl << "Matrix three is:" << endl;
    m3.Print();
    cout << endl << "Matrix that is a result of adding two different matrices (one and three) is:" << endl;
    m3.add(m1).Print();
    cout << endl << "The same result should give:" << endl;
    m1.add(m3).Print();

    cout << endl << "The following line should read \"Exception caught!\":" << endl;
    try {
        Matrix m4("[1 2; 5 6]");
        m4.add(m1);
    } catch (...) {
        cout << "Exception caught!";
    }

    return 0;
}