#include <iostream>
#include "SumMethod.h"

template <class T>
T SumMethod::Sum(T a, T b) {
    T c;
    c = a + b;

    return c;
}

std::complex<double> SumMethod::Sum(std::complex<double> a, std::complex<double> b) {
    std::complex<double> c(a.real() + b.real(), a.imag() + b.imag());
    return c;
}