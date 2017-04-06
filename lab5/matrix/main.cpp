//
// Created by Grzegorz on 04.04.2017.
//

#include "Matrix.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using algebra::Matrix;

int main() {
    string str = "[13i65 2.0 3; 7 4 3]";

    Matrix m1(str);
    Matrix m2(m1);

    m1.Print();
    cout << endl;
    m2.Print();
    
    return 0;
}