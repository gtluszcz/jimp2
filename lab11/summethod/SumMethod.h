#ifndef JIMP_EXERCISES_SUMMETHOD_H
#define JIMP_EXERCISES_SUMMETHOD_H

#include <complex>

class SumMethod {
public:
    template <class T>
    T Sum(T a, T b);

    std::complex<double> Sum(std::complex<double> a, std::complex<double> b);
};

#endif //JIMP_EXERCISES_SUMMETHOD_H
