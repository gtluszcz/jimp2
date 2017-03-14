//
// Created by Grzegorz on 14.03.2017.
//

#include "GreatestProduct.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;


int GreatestProduct(const vector<int> &numbers, int k){
    vector<int> iloczyndodatnich = {1,1};
    vector<int> iloczynujemnych = {-1,-1};
    for (int v : numbers) {
        if (iloczyndodatnich[1]*v > iloczyndodatnich[1]*iloczyndodatnich[0]){
            iloczyndodatnich[0]=iloczyndodatnich[1];
            iloczyndodatnich[1]=v;
        }
        if (iloczynujemnych[1]*v > iloczynujemnych[1]*iloczynujemnych[0]){
            iloczynujemnych[0]=iloczynujemnych[1];
            iloczynujemnych[1]=v;
        }
    }
    int result = max(iloczyndodatnich[1]*iloczyndodatnich[0],iloczynujemnych[1]*iloczynujemnych[0]);
    return result;
}

