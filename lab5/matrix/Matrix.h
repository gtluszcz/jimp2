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
        Matrix Add(Matrix matrix);
        Matrix Sub(Matrix matrix);
        Matrix Mul(Matrix matrix);
        Matrix Mul(complex<double> number);
        Matrix Pow(int number);
        complex<double> ** getMatrix();
        int getWidth();
        int getHeight();
        std::string Print();
        ~Matrix();
    };
}

#endif //JIMP_EXERCISES_MATRIX_H
