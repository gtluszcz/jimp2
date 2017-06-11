//
// Created by tlusgrze on 23.05.17.
//

#include <iostream>
#include "Factorymethod.h"
//template <class T>
//void Factory<T>::factorymethod(){
//    T obj = T();
//
//}
template<class one>
one Sum(one left,one right){
    return left + right;
};