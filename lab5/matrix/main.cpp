//
// Created by Grzegorz on 04.04.2017.
//

#include "Matrix.h"
#include <iostream>

using std::cout;
using std::endl;
using algebra::Matrix;

int main() {
    Matrix m1("[13i65, 2.5i4.3, 3; 7, 4, 3]");
    Matrix m2(m1);

    cout << "Matrix one is:" << endl;
    cout << m1.Print();
    cout << endl << "Matrix two (same as one) is:" << endl;
    cout << m2.Print();
    cout << endl << "Matrix that is a result of adding two same matrices (one and two) is:" << endl;
    cout << m1.Add(m2).Print();

    Matrix m3("[1 2 3; 4 5 6]");
    cout << endl << "Matrix three is:" << endl;
    cout << m3.Print();
    cout << endl << "Matrix that is a result of adding two different matrices (one and three) is:" << endl;
    cout << m3.Add(m1).Print();
    cout << endl << "The same result should give:" << endl;
    cout << m1.Add(m3).Print();

    cout << endl << "The following line should read \"Exception caught!\":" << endl;
    try {
        Matrix m4("[1 2; 5 6]");
        m4.Add(m1);
    } catch (...) {
        cout << "Exception caught!" << endl;
    }

    cout << endl << "Multiplication of matrix by number:" << endl;
    cout << m1.Mul(complex<double>(3, 7)).Print();
    cout << endl << "Multiplication of matrix by matrix:" << endl;
    Matrix m5("[1 2 3; 3 4 5]");
    Matrix m6("[1 4.4; 2 5; 3 6]");
    cout << m5.Mul(m6).Print();

    cout << endl << "Matrix 7 to the power of two is:" << endl;
    Matrix m7("[1 2 3; 4 5 6; 7 8 9]");
    cout << m7.Pow(2).Print();

    return 0;
}
