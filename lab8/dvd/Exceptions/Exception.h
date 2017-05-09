#ifndef JIMP_EXERCISES_EXCEPTION_H
#define JIMP_EXERCISES_EXCEPTION_H

#include <string>

using std::string;

class Exception {
protected:
    string message_;
public:
    Exception(string message);
    string message() const;
};

#endif //JIMP_EXERCISES_EXCEPTION_H
