//
// Created by Grzegorz on 04.04.2017.
//

#include "Matrix.h"


int main() {
    string str = "[13i65 2.0 3; 7 4 3]";

    Matrix m1(str);
    Matrix m2(m1);

    m1.Print();
    m2.Print();
    
    return 0;
}