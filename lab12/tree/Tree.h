#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <iostream>
#include "Node.h"
#include "Node.cpp"

namespace tree {
    template<class T>
    class Tree {
    public:
        Tree();
        ~Tree();
        Tree(T value);
        Node<T> * Search(T value);
        Node<T> * RealSearch(Node<T> * node, T value);
        void PrintNode(Node<T> * node);
        void PrintTree();
        int Size();
        int Depth();
        T Value();
        void Insert(T value);
        Node<T> * root;
        int MaxDepth(Node<T> * node);
        void PrintPreorder();
        void PrintPreorder(Node<T> * node);
        void PrintInorder();
        void PrintInorder(Node<T> * node);
        void PrintPostorder();
        void PrintPostorder(Node<T> * node);

        int size;
    };
}

#endif //JIMP_EXERCISES_TREE_H
