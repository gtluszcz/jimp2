#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <vector>

using std::vector;

namespace tree {
    class Tree {
    public:
        Tree(vector<Leaf> leaves);
        void addLeaf(Leaf leaf);

    private:
        vector<Leaf> leaves_;
    };

    template <class T>
    class Leaf {
    public:
        Leaf(T value);

    private:
        T value_;
    };
}

#endif //JIMP_EXERCISES_TREE_H
