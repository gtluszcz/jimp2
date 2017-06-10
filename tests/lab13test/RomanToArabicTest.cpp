#include <gtest/gtest.h>
#include <ArabicRoman.h>
#include <vector>
#include <utility>
#include <string>

using namespace std;

TEST(roman_test, roman_is_parsed_correctly) {
    vector<pair<string, int>> results{
        {"I", 1}, {"II", 2}, {"III", 3}, {"IV", 4}, {"V", 5}, {"VI", 6}, {"VII", 7}, {"VIII", 8}, {"IX", 9}, {"X", 10},
        {"XX", 20}, {"XXX", 30}, {"XL", 40}, {"L", 50}, {"LX", 60}, {"LXX", 70}, {"LXXX", 80}, {"XC", 90}, {"C", 100},
        {"XVI", 16}, {"XLVII", 47}
    };

    for (auto & result : results) {
        EXPECT_EQ(result.second, romanToArabic(result.first));
    }
}

TEST(roman_test_exception, invalid_roman_throws_exception) {
    EXPECT_THROW(romanToArabic("IIII"), InvalidRomanNumeralException);
}
