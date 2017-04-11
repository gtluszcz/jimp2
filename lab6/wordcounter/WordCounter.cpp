//
// Created by Grzegorz on 10.04.2017.
//

#include "WordCounter.h"
using ::datastructures::WordCounter;
using ::datastructures::Counts;
using ::datastructures::Word;


int WordCounter::DistinctWords(){
    int counter = 0;
    for(auto &j: this->wordsdata){
        counter++;
    }
    return counter;
}
int WordCounter::TotalWords(){
    int counter = 0;
    for(auto &j: this->wordsdata){
        counter+=j.second.GetCounts();
    }
    return counter;
}
set<Word> WordCounter::Words(){
    set<Word> set1;
    for(auto j: this->wordsdata){
        set1.emplace(j.first);
    }
    return set1;
}
WordCounter::WordCounter(){}
WordCounter::WordCounter(std::initializer_list<Word> list){
    for (auto i=list.begin(); i!=list.end();i++){
        bool append = true;
        for(auto &j: this->wordsdata){
            if (i->GetWord()==j.first.GetWord()){
                append = false;
                ((&j)->second)++;
            }
        }
        if (append){
            this->wordsdata.emplace_back(make_pair(Word(*i),Counts(1)));
        }
    }
}

std::vector<std::pair<Word,Counts>> WordCounter::GetSet() const{
    return wordsdata;
}
WordCounter::~WordCounter(){
    wordsdata.empty();
}

int WordCounter::operator[](std::string name){
    for(auto &j: this->wordsdata){
        if (name==j.first.GetWord()){
            return j.second.GetCounts();
        }
    }
}

void WordCounter::FromInputStream(std::ifstream &is){

}
bool compare(std::pair<Word,Counts> &lhs, std::pair<Word,Counts> &rhs){
    if (lhs.second.GetCounts()>rhs.second.GetCounts()){ return true;}
    else{return false;}
}

ostream &datastructures::operator<<(ostream &os, WordCounter &counter){
    std::vector<std::pair<datastructures::Word,datastructures::Counts>> tmp = counter.GetSet();
    sort(tmp.begin(), tmp.end(), compare);
    for (auto &n: tmp){
        os<<"("<<n.first.GetWord()<<" : "<<n.second.GetCounts()<<") ";
    }
    return os;
}










////////////WORD

Word::Word(std::string name){
    this->word = name;
}
Word::Word(){
    this->word="";
}

std::string Word::GetWord() const{
    return this->word;
}

bool Word::operator==(const Word &rhs) const{
    if (word==rhs.word){return true;}
    else{ return false;}
}

bool Word::operator<(const Word &rhs) const {
    return word < rhs.word;
}

bool Word::operator>(const Word &rhs) const {
    return rhs < *this;
}

bool Word::operator<=(const Word &rhs) const {
    return !(rhs < *this);
}

bool Word::operator>=(const Word &rhs) const {
    return !(*this < rhs);
}


///////////COUNTS
Counts::Counts(int ilosc){
    this->amount = ilosc;
}
Counts::Counts(){
    this->amount = 0;
}
int Counts::GetCounts(){
    return this->amount;
}
void Counts::SetCounts(int nr){
    this->amount = nr;
}
Counts* Counts::operator++(int){
    this->SetCounts(this->GetCounts()+1);
    return this;
}
bool Counts::operator<(Counts r){
    if (this->GetCounts()<r.GetCounts()){return true;}
    else{ return false;}
}
bool Counts::operator==(Counts r){
    if (this->GetCounts()==r.GetCounts()){return true;}
    else{ return false;}
}
bool Counts::operator==(int r) const{
    if (amount==r){return true;}
    else{ return false;}
}
bool Counts::operator>(Counts r){
    if (this->GetCounts()>r.GetCounts()){return true;}
    else{ return false;}
}