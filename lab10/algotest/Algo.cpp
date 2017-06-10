#include <algorithm>
#include "Algo.h"
bool pred(const int &a, int partition){

}
void algo::CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out){
    std::vector<int> myvector;
    myvector.resize(n_elements);
    std::copy_n(v.begin(),n_elements,myvector.begin());
    *out=myvector;
}

bool algo::Contains(const std::vector<int> &v, int element){
   return std::find(v.begin(),v.end(), element) != v.end();
}

void algo::InitializeWith(int initial_value, std::vector<int> *v){
    std::replace(v->begin(),v->end(),(*v)[0],initial_value);
}
