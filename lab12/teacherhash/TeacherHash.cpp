//
// Created by Grzegorz on 11.06.2017.
//

#include "TeacherHash.h"
using namespace academia;


//TeacherId
TeacherId::TeacherId() {
    value_=0;
}
TeacherId::TeacherId(int value) {
    value_=value;
}
TeacherId::operator int() const {
    return this->value_;
}



//Teacher
Teacher::Teacher(TeacherId id, std::string name, std::string workspace){
    name_=name;
    Id_=id;
    workspace_=workspace;
}

TeacherId Teacher::Id() {
    return this->Id_;
}
std::string Teacher::Name() {
    return this->name_;
}
std::string Teacher::Department(){
    return this->workspace_;
}

bool Teacher::operator ==(Teacher a) const {
    return (this->Id_ == a.Id() && this->workspace_ == a.Department() && this->name_ == a.Name());
}

bool Teacher::operator !=(Teacher a) const {
    return (this->Id_ != a.Id() || this->workspace_ != a.Department() || this->name_ != a.Name());
}