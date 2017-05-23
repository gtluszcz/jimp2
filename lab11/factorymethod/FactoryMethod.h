#ifndef JIMP_EXERCISES_FACTORYMETHOD_H
#define JIMP_EXERCISES_FACTORYMETHOD_H

namespace factoryMethod {
    template<class T>
    T Create() {
        return *(new T);
    }

    class MyType {
    public:
        const char * SayHello();
    };
}

#endif //JIMP_EXERCISES_FACTORYMETHOD_H
