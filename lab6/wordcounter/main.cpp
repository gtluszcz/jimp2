//
// Created by Grzegorz on 10.04.2017.
//

#include "WordCounter.h"
#include <iostream>

using std::cout;
using std::endl;
using ::datastructures::WordCounter;
using ::datastructures::Counts;
using ::datastructures::Word;



int main() {
//    cout<<"Hello World!"<<endl;
//    Counts a(1);
//    Counts b(2);
// cout<<a.GetCounts()<<endl;
//    cout<<b.GetCounts()<<endl;
//    if (a<b){cout<<"a<b"<<endl;}
//    if (a>b){cout<<"a>b"<<endl;}
//    if (a==b){cout<<"a==b"<<endl;}
//    a++;
//    cout<<a.GetCounts()<<endl;
//    cout<<b.GetCounts()<<endl;
//    if (a==b){cout<<"a==b"<<endl;}
//    Word w("siema");
//    cout<<w.GetWord()<<" end"<<endl;
    WordCounter counter {Word("a"), Word("p"), Word("kozak"), Word("b"), Word("b"), Word("b"), Word("b")};
    cout<<counter;
//    cout<<counter["a"]<<endl;
//    cout<<counter.DistinctWords()<<endl;
//    cout<<counter.TotalWords()<<endl;
//    if(a==1){
//      cout<<"gites";
//    }
    return 0;
}