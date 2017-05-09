#include "Backpack.h"
#include <iostream>


Backpack::Backpack(int volume) {
    this->maxvolume_ = volume;
}

void Backpack::addProduct(Product name) {
    if (name.volume_ + this->volume_ <= this->maxvolume_) {
        products.push_back(name);
        this->volume_ += name.volume_;
    }
}
void Backpack::showBackpack() {
    int counter = 1;

    for (auto & n : this->products) {
        std::cout << counter << ". " << n.name_ << n.alcohol_ << n.volume_ << std::endl;
    }
}
