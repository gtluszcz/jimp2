#ifndef JIMP_EXERCISES_LOGGER_H
#define JIMP_EXERCISES_LOGGER_H

namespace Logger {
    class Logger {
        template<class T>
        Logger(T output);

        void debug();
        void info();
        void warning();
        void error();
    };
}

#endif //JIMP_EXERCISES_LOGGER_H
