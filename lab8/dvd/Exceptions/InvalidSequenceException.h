#ifndef JIMP_EXERCISES_INVALIDSEQUENCEEXCEPTION_H
#define JIMP_EXERCISES_INVALIDSEQUENCEEXCEPTION_H

#include "Exception.h"
#include <string>

using std::string;

class InvalidSequenceException : public Exception {
public:
    InvalidSequenceException(string message);
};

#endif //JIMP_EXERCISES_INVALIDSEQUENCEEXCEPTION_H
