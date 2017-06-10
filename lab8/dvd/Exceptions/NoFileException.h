#ifndef JIMP_EXERCISES_NOFILEEXCEPTION_H
#define JIMP_EXERCISES_NOFILEEXCEPTION_H

#include "Exception.h"
#include <string>

using std::string;

class NoFileException : public Exception {
public:
    NoFileException(string message);
};

#endif //JIMP_EXERCISES_NOFILEEXCEPTION_H
