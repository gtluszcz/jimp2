//
// Created by Grzegorz on 28.03.2017.
//

#include "TextPool.h"
#include <iostream>
#include <set>
using pool::TextPool;


//Rule of Five (z usuniętą możliwością kopiowania)

//1. konstruktor kopiujący
//TextPool(const TextPool &xxx);

//2. konstruktor przenoszący
TextPool::TextPool(TextPool &&xxx){
    swap(tekst,xxx.tekst);

}

//3. operator przypisania kopiujący
//TextPool &operator=(const TextPool &xxx);

//4. operator przypisania przenoszący
TextPool & TextPool::operator=(TextPool &&xxx){
    if (this == &xxx) {
        return xxx;
    }
    //w przyciwynym wypadku mamy x = move(y);
    //musimy sami zwolnic pamięć po x (czyli this):
    tekst.clear();
    //i wreszcie przenosimy stan, ten kod jest
    //jest identyczny więc można by go wydzielić do innej metody...
    swap(tekst,xxx.tekst);
    return *this;

}

//5. Destruktor
TextPool::~TextPool(){
    tekst.clear();
}

//domyślny konstruktor
TextPool::TextPool(){}

//konstruktor z listą inicjalizacyjną
TextPool::TextPool(const std::initializer_list<const std::string> &elements){

    for (auto i=elements.begin(); i!=elements.end(); i++) {
        //std::cout<<*i<<std::endl;
        tekst.emplace(*i);

    }
}

std::experimental::string_view TextPool::Intern(const std::string &str){
    bool flag = true;
    for (auto &n : this->tekst) {
        if (n == str){
            flag = false;
            return n;
        }
    }
    if (flag){
        tekst.emplace(str);
        return Intern(str);
    }
}

size_t TextPool::StoredStringCount() const{
    size_t size = 0;
    for (auto &n : this->tekst) {
        size+=1;
    }
    return size;
}
