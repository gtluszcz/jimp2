//
// Created by Grzegorz on 04.04.2017.
//

#include "Matrix.h"
#include <iostream>

using std::cout;
using std::endl;
using algebra::Matrix;

int main() {
    Matrix m1("[13i65 2.5i4.3 3; 7 4 3]");
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
        cout << "Exception caught!" << endl;
    }

    cout << endl << "Multiplication of matrix by number:" << endl;
    m1.multiply(complex<double>(3, 7)).Print();
    cout << endl << "Multiplication of matrix by matrix:" << endl;
    Matrix m5("[1 2 3; 3 4 5]");
    Matrix m6("[1 4; 2 5; 3 6]");
    m5.multiply(m6).Print();

    return 0;
}
