#ifndef JIMP_EXERCISES_STUDENT_H
#define JIMP_EXERCISES_STUDENT_H

#include "Backpack.h"

class Student {
public:
    Backpack *backpack_;
    Student(Backpack *name);
    void grabproduct(Product name);
};

#endif //JIMP_EXERCISES_STUDENT_H
