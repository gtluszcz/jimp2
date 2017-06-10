#ifndef JIMP_EXERCISES_LOGGER_H
#define JIMP_EXERCISES_LOGGER_H

#include <string>

namespace logger {
    template<class T>
    class Logger {
        T * output_;
    public:
        Logger(T * output);

        void debug(const char * text);
        void info(const char * text);
        void warning(const char * text);
        void error(const char * text);
    };
}

#endif //JIMP_EXERCISES_LOGGER_H
