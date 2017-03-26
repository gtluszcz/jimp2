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
    View view = View::View("{{template_with_underscore}} cos {{temp}} cos {{template_with_undersocre_missing}}");
    cout<<view.GetTekst()<<endl;
    cout<<view.Render({{"template_with_underscore", "replacement"}});
}