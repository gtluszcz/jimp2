#ifndef JIMP_EXERCISES_BACKPACK_H
#define JIMP_EXERCISES_BACKPACK_H

#include <vector>
#include "products/Product.h"
using namespace std;

class Backpack  {
public:
    int volume_ = 10;
    int maxvolume_;
    std::vector<Product> products;
    Backpack(int volume);
    void addProduct(Product name);
    void showBackpack();

};


#endif //JIMP_EXERCISES_BACKPACK_H
