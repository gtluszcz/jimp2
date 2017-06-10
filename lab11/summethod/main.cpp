#include "SumMethod.h"
#include <complex>
#include <iostream>

int main() {
    SumMethod s;

    int s1 = s.Sum(3, 4);
    std::cout << "Suma 3 i 4 to =" << s1 << std::endl;

    double s2 = s.Sum(3.14, 4.32);
    std::cout << "Suma 3.14 i 4.32 to =" << s2 << std::endl;

    std::complex<double> a(3.0, 2.0);
    std::complex<double> b(4.3, 3.2);
    std::complex<double> s3 = s.Sum(a, b);
    std::cout << "Suma (3.0, 2.0) i (4.3, 3.2) to =" << s3 << std::endl;

    return 0;
};