#include <cstdlib>
#include "Store.h"
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>

using boost::mt19937;
using boost::uniform_int;
using boost::variate_generator;

Product Store::addProduct(Product product) {
    products_.push_back(product);
}

Product Store::getRandomProduct() {
    mt19937 range;
    uniform_int<> random(0, products_.size());
    variate_generator<mt19937&, uniform_int<>> die(range, random);
    int x = die();

    return products_[x];
}

Store::Store() {
}

Store::Store(vector<Product> &products) {
    products_ = products;
}
