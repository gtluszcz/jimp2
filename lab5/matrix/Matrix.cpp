//
// Created by Grzegorz on 04.04.2017.
//

#include <complex>
#include "Matrix.h"


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
    cout << "Dzien dobry, tu Twoja macierz."<<endl;
}

Matrix::~Matrix() {
    cout << "Do widzenia!"<<endl;
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
                liczba_re = liczba.substr(0, liczba.find("i"));
                liczba_im = liczba.substr(liczba.find("i")+1, liczba.length()-liczba.find("i"));
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
                liczba_re = liczba.substr(0, liczba.find("i"));
                liczba_im = liczba.substr(liczba.find("i")+1, liczba.length()-liczba.find("i"));
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
            cout << macierz[o][p];
        }
        cout<<endl;
    }

}
