//
// Created by Grzegorz on 04.04.2017.
//

#include <complex>
#include "Matrix.h"

using algebra::Matrix;

Matrix::Matrix(int n, int m) {
    this->n=n;
    this->m=m;
    macierz = new complex<double>*[n];
    for (int i=0; i<n; ++i){
        macierz[i] = new complex<double>[m];
    }
}

Matrix::Matrix(Matrix &ziemniak) {
    n = ziemniak.n;
    m = ziemniak.m;
    macierz = new complex<double>*[n];
    for (int i=0; i<n; ++i){
        macierz[i] = new complex<double>[m];
        for(int x=0;x<m;x++)
        {
            macierz[i][x]=ziemniak.macierz[i][x];
        }
    }
}

Matrix::Matrix() {
//    cout << "Dzien dobry, tu Twoja macierz."<<endl;
}

Matrix::~Matrix() {
//    cout << "Do widzenia!"<<endl;
}

Matrix::Matrix(std::string matlabowe_cos) {
    int n = 1, m = 1;
    string::size_type sz;
    string liczba = "", liczba_re = "", liczba_im = "";
    double liczba_double, liczba_re_double,liczba_im_double;
    for (string::iterator it = matlabowe_cos.begin(); it != matlabowe_cos.end(); ++it) {
        if (*it == 32) m++;
        if (*it == 59) n++;
    }
    m=m/n;
    this->n = n;
    this->m = m;
    macierz = new complex<double> *[n];
    for (int i = 0; i < n; ++i) {
        macierz[i] = new complex<double>[m];
    }

    int i = 0, j = 0;
    for (string::iterator it = matlabowe_cos.begin(); it != matlabowe_cos.end(); ++it) {
        if ((*it <= 57 && *it >= 48) ||  *it == 105 || *it == 46) {
            //cout << " ";
            liczba += *it;

        }
        else if (*it == ' ' || *it == ']') {
            if (liczba.find("i") != string::npos) {
                for (int k = 0; k != liczba.find("i"); k++) {
                    liczba_re += liczba[k];
                    liczba_im += liczba[liczba.length() - k -1];
                }
                liczba_re_double = stod(liczba_re, &sz);
                liczba_im_double = stod(liczba_im, &sz);
                macierz[i][j] = complex<double>(liczba_re_double, liczba_im_double);
                j++;
                liczba = "";
                liczba_re = "";
                liczba_im = "";
            } else {
                liczba_double = stod(liczba, &sz);
                macierz[i][j] = complex<double>(liczba_double);
                j++;
                liczba = "";
            }
        }
        else if (*it == 59) {
            if (liczba.find("i") != string::npos) {
                for (int k = 0; k != liczba.find("i"); k++) {
                    liczba_re += liczba[k];
                    liczba_im += liczba[liczba.length() - k];
                }
                liczba_re_double = stod(liczba_re, &sz);
                liczba_im_double = stod(liczba_im, &sz);
                macierz[i][j] = complex<double>(liczba_re_double, liczba_im_double);
                i++;
                j=0;
                liczba = "";
                liczba_re = "";
                liczba_im = "";
            } else {
                liczba_double = stod(liczba, &sz);
                macierz[i][j] = complex<double>(liczba_double);
                i++;
                j=0;
                liczba = "";

            }
            *it++;
        }
    }

}

void Matrix::Print() {
    for(int o=0;o<n;o++){
        for(int p=0;p<m;p++){
            cout << macierz[o][p] << " ";
        }
        cout<<endl;
    }
}

Matrix Matrix::add(Matrix matrix) {
    if (m != matrix.getWidth() || n != matrix.getHeight()) {
        throw "Cannot add matrices of different sizes!";
    }

    Matrix result(matrix.getHeight(), matrix.getWidth());

    for (int o = 0; o < n; o++) {
        for (int p = 0; p < m; p++) {
            result.getMatrix()[o][p] = macierz[o][p] + matrix.getMatrix()[o][p];
        }
    }

    return result;
}

Matrix Matrix::multiply(Matrix matrix) {
    if (n != matrix.getWidth()) {
        throw "Cannot multiply matrices when the first matrix has different height than second has width!";
    }

    Matrix result(n, matrix.getWidth());

    for (int o = 0; o < n; o++) {
        for (int p = 0; p < matrix.getWidth(); p++) {
            result.getMatrix()[o][p] = 0;
            for (int k = 0; k < matrix.getHeight(); k++) {
                result.getMatrix()[o][p] += macierz[o][k] * matrix.getMatrix()[k][p];
            }
        }
    }

    return result;
}

Matrix Matrix::multiply(complex<double> number) {
    Matrix result(n, m);

    for (int o = 0; o < n; o++) {
        for (int p = 0; p < m; p++) {
            result.getMatrix()[o][p] = macierz[o][p] * number;
        }
    }

    return result;
}

complex<double> ** Matrix::getMatrix() {
    return macierz;
}

int Matrix::getHeight() {
    return n;
}

int Matrix::getWidth() {
    return m;
}
