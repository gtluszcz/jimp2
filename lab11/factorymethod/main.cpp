#include <iostream>
#include <vector>
#include "FactoryMethod.h"

using std::cout;
using factoryMethod::Create;
using factoryMethod::MyType;

int main() {
    int i = Create<int>();
    cout << (0 == i);

    double d = Create<double>();
    cout << (0.0 == d);

    std::string s = Create<std::string>();
    cout << ("" == s);

    std::vector<double> v = Create<std::vector<double>>();
    cout << (0 == v.size());

    MyType m = Create<MyType>();
    cout << (strcmp("hello", m.SayHello()) == 0);

    return 0;
}
