#include "products/Vodka.h"
#include "products/Water.h"
#include "products/Beer.h"
#include "Store.h"
#include "Backpack.h"
#include "Student.h"

int main() {
    Vodka vodka1("Sobieski", 500, 0.40);
    Vodka vodka2("Finlandia", 500, 0.40);
    Vodka vodka3("Pan Tadeusz", 500, 0.40);
    Beer beer1("Warka", 500, 0.04);
    Beer beer2("Tyskie", 500, 0.04);
    Beer beer3("Kozel", 500, 0.04);
    Water water1("Żywiec Zdrój", 500, 0.0);
    Water water2("Cisowianka", 500, 0.0);
    Water water3("Nałęczowianka", 500, 0.0);

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
