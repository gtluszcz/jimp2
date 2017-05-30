#include "Tree.h"

using tree::Tree;
using tree::Leaf;

Tree::Tree(vector<Leaf> leaves) {
    leaves_ = leaves;
}

void Tree::addLeaf(tree::Leaf leaf) {
    leaves_.push_back(leaf);
}

template <class T>
Leaf::Leaf(T value) {
    value_ = value;
}
