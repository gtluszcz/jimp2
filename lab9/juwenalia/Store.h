#ifndef JIMP_EXERCISES_STORE_H
#define JIMP_EXERCISES_STORE_H

#include <vector>
#include "products/Product.h"

using std::vector;

class Store {
    vector<Product> products_;

public:
    Store(vector<Product> &products);
    Store();
    Product addProduct(Product product);
    Product getRandomProduct();
};

#endif //JIMP_EXERCISES_STORE_H
