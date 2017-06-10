//
// Created by Grzegorz on 10.06.2017.
//

#ifndef JIMP_EXERCISES_SEQUENTIALGENERATOR_H
#define JIMP_EXERCISES_SEQUENTIALGENERATOR_H
template<class T,class U>
class SequentialIdGenerator{
public:
    SequentialIdGenerator(U value);
    SequentialIdGenerator();
    int actualvalue;
    T NextValue();

};

template<class T,class U>
SequentialIdGenerator<T,U>::SequentialIdGenerator(U value){
    this->actualvalue = (int)value;

}

template<class T,class U>
SequentialIdGenerator<T,U>::SequentialIdGenerator(){
    this->actualvalue = (int)U();

}
template<class T,class U>
T SequentialIdGenerator<T,U>::NextValue(){
    auto tmp = int(this->actualvalue);
    (this->actualvalue)++;
    return T(tmp);
}
#endif //JIMP_EXERCISES_SEQUENTIALGENERATOR_H
