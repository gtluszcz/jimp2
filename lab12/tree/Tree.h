#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <iostream>
#include <vector>
#include "Node.h"
#include "Node.cpp"

using std::vector;

namespace tree {
    template<class T>
    class Tree {
    public:
        Tree();
        ~Tree();
        void DeleteTree(Node<T> * node);
        Tree(T value);
        Node<T> * Search(T value);
        Node<T> * Search(Node<T> * node, T value);
        int Size();
        T Value();
        void Insert(T value);
        int Depth();
        int Depth(Node<T> * node);
        void PrintNode(Node<T> * node);
        void PrintTree();
        void PrintPreorder();
        void PrintPreorder(Node<T> * node);
        void PrintInorder();
        void PrintInorder(Node<T> * node);
        void PrintPostorder();
        void PrintPostorder(Node<T> * node);

        Node<T> * root;
        int size;
    };
}

#endif //JIMP_EXERCISES_TREE_H
