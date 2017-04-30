#include "Exception.h"

Exception::Exception(string message) : message_(message) {}

string Exception::message() const {
    return message_;
}