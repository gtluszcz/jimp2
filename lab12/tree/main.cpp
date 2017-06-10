#include <iostream>
#include "Tree.h"

using namespace tree;

int main() {
    int liczba = 8;
    Tree<int> newtree = Tree<int>();
    newtree.Addchild(8);
    newtree.Printtree();
}
