#include "Pesel.h"
#include <iostream>

int main() {
    try {
        Pesel p1("97113004357");
        std::cout << "Correct Pesel provided!" << std::endl;
    } catch (InvalidPeselException e) {
        std::cout << "Invalid Pesel provided!" << std::endl;
    }

    try {
        Pesel p2("97113004358");
        std::cout << "Correct Pesel provided!" << std::endl;
    } catch (InvalidPeselException e) {
        std::cout << "Invalid Pesel provided!" << std::endl;
    }

    return 0;
}