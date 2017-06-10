//
// Created by Grzegorz on 10.04.2017.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

namespace datastructures {
    class Counts {
    private:
        int amount;

    public:
        Counts(int ilosc);
        Counts();
        int GetCounts();
        void SetCounts(int nr);
        Counts* operator++(int);

        bool operator<(Counts r);
        bool operator==(Counts r);
        bool operator==(int r) const;
        bool operator>(Counts r);
    };


    class Word {
    private:
        std::string word;

    public:
        Word(std::string name);
        Word();
        std::string GetWord() const;

        bool operator<(const Word &rhs) const;
        bool operator>(const Word &rhs) const;
        bool operator<=(const Word &rhs) const;
        bool operator>=(const Word &rhs) const;
        bool operator==(const Word &rhs) const;
    };


    class WordCounter {
    private:
        std::vector<std::pair<datastructures::Word,datastructures::Counts>> wordsdata;

    public:
        int DistinctWords();
        int TotalWords();
        std::set<datastructures::Word> Words();
        WordCounter();
        WordCounter(std::initializer_list<datastructures::Word> list);
        std::vector<std::pair<datastructures::Word,datastructures::Counts>> GetSet() const;
        ~WordCounter();
        void FromInputStream(std::ifstream &is);
        int operator[](std::string name);


    };

    ostream &operator<<(ostream &os, WordCounter &counter);


}

#endif //JIMP_EXERCISES_WORDCOUNTER_H
