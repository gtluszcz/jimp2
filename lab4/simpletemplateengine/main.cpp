//
// Created by Grzegorz on 21.03.2017.
//
#include "SimpleTemplateEngine.h"
#include <iostream>
#include <string>
#include <unordered_map>
using namespace nets;
using namespace std;

int main(){
    cout<<"Gitara"<<endl;
    View view = View::View("Siema");
    cout<<view.GetTekst();
}