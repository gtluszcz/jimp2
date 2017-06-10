#include <iostream>
#include "Tree.h"

using namespace tree;
using namespace std;

int main() {
    Tree<int> tree {5};
    cout << "Root:" << tree.Value() << endl;
    cout << "Size: " << tree.Size() << endl;
}
