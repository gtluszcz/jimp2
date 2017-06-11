#include <iostream>
#include "Tree.h"
#include "Tree.cpp"

using namespace tree;
using namespace std;

int main() {
    Tree<int> tree {5};
    cout << "Root:" << (5 == tree.Value()) << endl;
    cout << "Size: " << (1 == tree.Size()) << endl;
    cout << "Depth: " << (1 == tree.Depth()) << endl;

    tree.Insert(0);
    cout << "Root:" << (5 == tree.Value()) << endl;
    cout << "Size: " << (2 == tree.Size()) << endl;
    cout << "Depth: " << (2 == tree.Depth()) << endl;

    tree.Insert(102);
    cout << "Root:" << (5 == tree.Value()) << endl;
    cout << "Size: " << (3 == tree.Size()) << endl;
    cout << "Depth: " << (2 == tree.Depth()) << endl;

    tree.Insert(890);
    cout << "Root:" << (5 == tree.Value()) << endl;
    cout << "Size: " << (4 == tree.Size()) << endl;
    cout << "Depth: " << (3 == tree.Depth()) << endl;

    tree.Insert(81);
    cout << "Root:" << (5 == tree.Value()) << endl;
    cout << "Size: " << (5 == tree.Size()) << endl;
    cout << "Depth: " << (3 == tree.Depth()) << endl;

    tree.Insert(-1);
    cout << "Root:" << (5 == tree.Value()) << endl;
    cout << "Size: " << (6 == tree.Size()) << endl;
    cout << "Depth: " << (3 == tree.Depth()) << endl;

    tree.PrintTree();
}
