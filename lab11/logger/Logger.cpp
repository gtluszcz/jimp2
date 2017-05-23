#include "Logger.h"

template<class T>
logger::Logger<T>::Logger(T * output) {
    output_ = output;
}

template<class T>
void logger::Logger<T>::debug(const char * text) {
    *output_ << "[debug]" << text << "\n";
}

template<class T>
void logger::Logger<T>::warning(const char * text) {
    *output_ << "[warning]" << text << "\n";
}

template<class T>
void logger::Logger<T>::error(const char * text) {
    *output_ << "[error]" << text << "\n";
}

template<class T>
void logger::Logger<T>::info(const char * text) {
    *output_ << "[info]" << text << "\n";
}
