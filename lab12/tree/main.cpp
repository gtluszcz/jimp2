#include "Tree.h"

using tree::Leaf;
using tree::Tree;

int main() {
    vector<Leaf> leaves = {
        Leaf {10},
        Leaf {10.1},
        Leaf {"9"},
        Leaf {"9.1"}
    };

    Tree tree(leaves);



    return 0;
}