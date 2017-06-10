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
    View view = View::View("Test {{test}} {{injected}}");
    cout<<view.GetTekst()<<endl;
    cout<<view.Render({{"test", "{{injected}}"}, {"injected", "{{test}}"}});
}