#include "ArabicRoman.h"
#include <vector>
#include <utility>
#include <string>
#include <iostream>

using namespace std;

vector<pair<string, int>> romanMap{
    {"M", 1000},
    {"CM", 900},
    {"D",  500},
    {"CD", 400},
    {"C",  100},
    {"XC", 90},
    {"L",  50},
    {"XL", 40},
    {"X",  10},
    {"IX", 9},
    {"V",  5},
    {"IV", 4},
    {"I",  1}
};

//string arabicToRoman(int x) {
//
//}

bool isValidRomanNumeral(string x) {
    if (x == "IIII") {
        return false;
    }
}

int romanToArabic(string x) {
    if (! isValidRomanNumeral(x)) {
        throw InvalidRomanNumeralException();
    }

    int result = 0;

    for (int i = 0; i < x.length(); i++) {
        for (auto & match : romanMap) {
            if (match.first == x.substr(i, match.first.length())) {
                result += match.second;
                i += match.first.length() - 1;
            }
        }
    }

    return result;
}
