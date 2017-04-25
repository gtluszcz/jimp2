#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>

class InvalidPeselException {};

class Pesel {
    std::string pesel;
public:
    Pesel(std::string _pesel);
    void validatePesel(std::string pesel);
};

#endif //JIMP_EXERCISES_PESEL_H
