//
// Created by Grzegorz on 11.06.2017.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>


namespace academia{

    class TeacherId{
    public:
        TeacherId();
        TeacherId(int value);
        operator int() const;


    private:
        int value_;
    };

    class Teacher{
    public:
        Teacher(TeacherId id, std::string name, std::string workspace);
        TeacherId Id() const;
        std::string Name() const;
        std::string Department() const;
        bool operator ==(Teacher a) const;
        bool operator !=(Teacher a) const;
    private:
        TeacherId Id_;
        std::string name_;
        std::string workspace_;
    };

    class TeacherHash{
    public:
        size_t operator ()(const Teacher &teacher) const;
    };
}



#endif //JIMP_EXERCISES_TEACHERHASH_H
