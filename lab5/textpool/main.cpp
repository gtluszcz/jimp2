//
// Created by Grzegorz on 28.03.2017.
//
#include <iostream>
#include "TextPool.h"

using namespace pool;
using namespace std;

int main() {
    //Inicjalizacja wstępna puli za pomocą listy inicjalizacyjnej
    TextPool pool {"abc", "efg", "hij", "klmn", "oprst"};
    TextPool new1(move(pool));
    //TextPool new2;
    //new1=move(new2=move(pool));
    cout << new1.StoredStringCount() << endl;

    //wstawienie napisu do puli
    auto s1 = new1.Intern("lel");
    cout << new1.StoredStringCount() << endl;

    //wstawienie kolejnego napisu do puli (w obu przypadkach nie
    //powinien się zmienić rozmiar puli)
    auto s2 = new1.Intern("lel");

    cout << (s1 == s2 ? "True" : "False") << endl; //uchwyty są tymi samymi napisami co do wartości
    cout << new1.StoredStringCount() << endl; // w puli jest wciąż 5 napisów
    cout << (s1.begin() == s2.begin() ? "True" : "False") << endl; //na dodatek uchywyty s1 i s2 pokazują dokładnie na ten sam napis w puli (wskaźniki są identyczne)
}
