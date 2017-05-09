#include "products/Vodka.h"
#include "products/Water.h"
#include "products/Beer.h"
#include "Store.h"
#include "Backpack.h"
#include "Student.h"

int main() {
    Vodka vodka1;
    Vodka vodka2;
    Vodka vodka3;
    Beer beer1;
    Beer beer2;
    Beer beer3;
    Water water1;
    Water water2;
    Water water3;

    Store store;
    store.addProduct(water3);
    store.addProduct(beer1);
    store.addProduct(vodka2);
    store.addProduct(water2);
    store.addProduct(vodka3);
    store.addProduct(beer3);
    store.addProduct(vodka1);
    store.addProduct(water1);
    store.addProduct(beer2);

    Backpack * backpack();
    Student student(backpack);

//    student.grabProduct(store.getRandomProduct());

    return 0;
}
