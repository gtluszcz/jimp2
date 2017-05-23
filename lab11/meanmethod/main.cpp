#include "MeanMethod.h"
#include <complex>
#include <iostream>
#include <vector>

int main() {
    MeanMethod s;
    std::vector<int> v1 = {7, 5, 16, 8};
    std::vector<double> v2 = {7.2, 5.3, 16.2, 8.1};
    std::complex<double> c1(7.0, 3.0);
    std::complex<double> c2(7.0, 3.0);
    std::complex<double> c3(16, 8);
    std::vector<std::complex<double>> v3 = {c1, c2, c3};

    int s1 = s.Mean(v1);
    std::cout << "Średnia 7, 5, 16, 8 to =" << s1 << std::endl;

    double s2 = s.Mean(v2);
    std::cout << "Średnia 7.2, 5.3, 16.2, 8.1 to =" << s2 << std::endl;

    std::complex<double> s3 = s.Mean(v3);
    std::cout << "Średnia (7.0, 3.0), (7.0, 3.0) i (16, 8) to =" << s3 << std::endl;

    return 0;
}