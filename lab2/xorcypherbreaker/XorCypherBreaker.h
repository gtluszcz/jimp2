//
// Created by Grzegorz on 09.03.2017.
//

#ifndef JIMP_EXERCISES_XORCYPHERBREAKER_H
#define JIMP_EXERCISES_XORCYPHERBREAKER_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

std::string XorCypherBreaker(const std::vector<char> &cryptogram,
                             int key_length,
                             const std::vector<string> &dictionary);
std::string XorDecypher(const std::vector<char> &cryptogram, const string key);
#endif //JIMP_EXERCISES_XORCYPHERBREAKER_H
