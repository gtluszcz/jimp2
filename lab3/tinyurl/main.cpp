//
// Created by Grzegorz on 16.03.2017.
//

#include "TinyUrl.h"
#include <utility>
#include <string>
#include <array>
#include <memory>
#include <iostream>

using namespace std;

int main(){
//    std::array<char, 6> chars = {'z','z','z','z','a','z'};
//    tinyurl::NextHash(&chars);
//    for (int i=0; i<6;i++)
//        cout<<chars[i];

    std::unique_ptr<tinyurl::TinyUrlCodec> codec = tinyurl::Init();
    tinyurl::Encode("siema", &codec);
    tinyurl::Encode("siema2", &codec);
    for (auto &n : *codec) {
        cout<<n.first<<" => "<<n.second<<endl;
    }
    cout<<tinyurl::Decode(codec, "000001");
}