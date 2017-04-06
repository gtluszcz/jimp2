//
// Created by Grzegorz on 04.04.2017.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <complex>

using namespace std;

namespace algebra {
    class Matrix {
        complex<double> ** macierz;
        int n;
        int m;

    public:
        Matrix(int, int);
        Matrix();
        Matrix(std::string);
        Matrix(Matrix &ziemniak);
        pair<size_t, size_t> Size();
        Matrix add(Matrix matrix);
        Matrix multiply(Matrix matrix);
        Matrix multiply(complex<double> number);
        complex<double> ** getMatrix();
        int getWidth();
        int getHeight();
        void Print();
        ~Matrix();
    };
}

#endif //JIMP_EXERCISES_MATRIX_H
