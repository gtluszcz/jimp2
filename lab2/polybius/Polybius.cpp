//
// Created by Grzegorz on 07.03.2017.
//

#include "Polybius.h"
#include <string.h>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;



std::string PolybiusCrypt(std::string message){
    map<char, string> v = {{'a',"11"}, {'b',"12"}, {'c',"13"}, {'d',"14"}, {'e',"15"}, {'f',"21"}, {'g',"22"}, {'h',"23"} , {'i',"24"} , {'j',"24"} , {'k',"25"} , {'l',"31"} , {'m',"32"} , {'n',"33"} , {'o',"34"} , {'p',"35"} , {'q',"41"} , {'r',"42"}, {'s',"43"}, {'t',"44"}, {'u',"45"}, {'v',"51"}, {'w',"52"}, {'x',"53"}, {'y',"54"}, {'z',"55"}};
    string result;
    string input=message;
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    unsigned long size = input.size();
    for(int i=0;i<size;i++){
        //cout<<result<<endl;
        for (auto &n : v) {
            if(n.first == input[i]){
                result+=n.second;
                break;
            }
        }
    }
    return result;
}
std::string PolybiusDecrypt(std::string crypted){
    map<char, string> v = {{'a',"11"4}, {'b',"12"}, {'c',"13"}, {'d',"14"}, {'e',"15"}, {'f',"21"}, {'g',"22"}, {'h',"23"} , {'i',"24"} , {'j',"24"} , {'k',"25"} , {'l',"31"} , {'m',"32"} , {'n',"33"} , {'o',"34"} , {'p',"35"} , {'q',"41"} , {'r',"42"}, {'s',"43"}, {'t',"44"}, {'u',"45"}, {'v',"51"}, {'w',"52"}, {'x',"53"}, {'y',"54"}, {'z',"55"}};
    string result;
    string input=crypted;
    unsigned long size = input.size();
    for(int i=0;i<size;i+=2){
        //cout<<result<<endl;
        for (auto &n : v) {
            if(n.second == input.substr(i, 2)){
                result+=n.first;
                break;
            }
        }
    }
    return result;
}