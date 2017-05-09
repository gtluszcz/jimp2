#include "Student.h"
Student::Student(Backpack *name){
    this->backpack_=name;
}
void Student::grabproduct(Product name){
    this->backpack_->addProduct(name);
}