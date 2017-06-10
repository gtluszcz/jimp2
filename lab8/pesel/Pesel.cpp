#include "Pesel.h"

const int ascii_code = 48;

Pesel::Pesel(std::string _pesel) {
    validatePesel(_pesel);
    pesel = _pesel;
}

void Pesel::validatePesel(std::string pesel) {
    if (pesel.length() != 11) {
        throw InvalidPeselException();
    }

    const int wages[] = {9, 7, 3, 1, 9, 7, 3, 1, 9, 7};
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += wages[i] * (pesel[i] - ascii_code);
    }

    if ((sum % 10) != (pesel[10] - ascii_code)) {
        throw InvalidPeselException();
    }
}
