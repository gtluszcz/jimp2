//
// Created by Grzegorz on 11.06.2017.
//

#include "TeacherHash.h"
#include <iostream>
using namespace std;
using namespace academia;
int main(){
    cout<<"Test1"<<endl;
    const TeacherId id(1002);
    int casted_id = id;
    if (casted_id == 1002){cout<<"     yes"<<endl;}
    if (id == 1002){cout<<"     yes"<<endl;}

    cout<<"Test2"<<endl;
    TeacherId id1 (300);
    TeacherId id2 (347);
    if (id1!=id2){cout<<"     yes"<<endl;}

    cout<<"Test3"<<endl;
    TeacherId id3 (612);
    TeacherId id4 (612);
    if (id3==id4){cout<<"     yes"<<endl;}

    cout<<"Test4"<<endl;
    Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
    if(TeacherId(1002)==s1.Id()){cout<<"     yes"<<endl;}
    if("Alozjzy"s==s1.Name()){cout<<"     yes"<<endl;}
    if("Katedra Informatyki"s==s1.Department()){cout<<"     yes"<<endl;}

    cout<<"Test5"<<endl;
    Teacher s2 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
    Teacher s3 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
    if(s2==s3){cout<<"     yes"<<endl;}

}