//
// Created by Grzegorz on 07.03.2017.
//
#include <iostream>
#include "Polybius.h"
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;


int main(int argc, char* argv[]) {
    if (argc == 4){
        if (*argv[3] == '1'){
            ifstream input(argv[1]);
            ofstream output (argv[2], ios_base::in | ios_base::app);
            char word[100];
            if(!input)
                cout << "Nie można otworzyć pliku!" << endl;
            if(!output)
                cout << "Nie można otworzyć pliku!" << endl;
            while(input >> word){
                output << PolybiusCrypt(word);
            }
            input.close();
            output.close();
        }
        else if (*argv[3] == '0') {
            ifstream input(argv[1]);
            ofstream output (argv[2], ios_base::in | ios_base::app);
            char word[100];
            if(!input)
                cout << "Nie można otworzyć pliku!" << endl;
            if(!output)
                cout << "Nie można otworzyć pliku!" << endl;
            while(input >> word){
                output << PolybiusDecrypt(word);
            }
            input.close();
            output.close();
        }
        else {cout <<"Zły argument 3"<<endl;}
    }
    else{cout <<"Zła liczba argumentów"<<endl;}
    return 0;
}
