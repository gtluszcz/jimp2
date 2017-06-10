#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <iostream>

namespace tree {
    template<class T>
    class Node {
    public:
        Node(T value);

        Node<T> * left;
        Node<T> * right;
        Node<T> * parent;
        T value;
        int key;
    };

    template<class T>
    Node<T>::Node(T value) {
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        this->value = value;
        this->key = (int) value;
    }

    template<class T>
    class Tree {
    public:
        Tree();
        ~Tree();
        Tree(T value);
        Node<T> * Search(T value);
        Node<T> * RealSearch(Node<T> * node, T value);
        void Printnode(Node<T> * root);
        void Printtree();
        int Size();
        int Depth();
        T Value();
        void Insert(T value);
        Node<T> * root;
        int MaxDepth(Node<T> * node);

        int size;
    };

    template<class T>
    Tree<T>::Tree() {
        this->root = nullptr;
        size = 0;
    }

    template<class T>
    Tree<T>::~Tree() {
        // go through each node postorder and 'delete' it
    }

    template<class T>
    Tree<T>::Tree(T value) {
        Node<T> * newnode = new Node<T>{value};
        this->root = newnode;
        size = 1;
    }

    template<class T>
    T Tree<T>::Value() {
        return root->value;
    }

    template<class T>
    int Tree<T>::Size() {
        return size;
    }

    template<class T>
    int Tree<T>::Depth() {
        return MaxDepth(root);
    }

    template<class T>
    int Tree<T>::MaxDepth(Node<T> * node) {
        if (node == nullptr) return 0;

        int lDepth = MaxDepth(node->left);
        int rDepth = MaxDepth(node->right);

        if (lDepth > rDepth) {
            return lDepth + 1;
        } else {
            return rDepth + 1;
        }
    }

    template<class T>
    void Tree<T>::Insert(T value) {
        Node<T> * z = new Node<T>{value};
        Node<T> * x = root;
        Node<T> * y = nullptr;

        while (x != nullptr) {
            y = x;
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        z->parent = y;

        if (y == nullptr) {
            root = z;
        } else if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }

        size++;
    }

    template<class T>
    Node<T> * Tree<T>::Search(T value) {
        return RealSearch(root, value);
    }

    template<class T>
    Node<T> * Tree<T>::RealSearch(Node<T> * x, T k) {
        if (x == nullptr || k == x->key) {
            return x;
        }
        if (k < x->key) {
            return RealSearch(x->left, k);
        } else {
            return RealSearch(x->right, k);
        }
    }

    template<class T>
    void Tree<T>::Printnode(Node<T> * root) {
        std::cout << root->key << std::endl;
        if (root->left != nullptr) Printnode(root->left);
        if (root->right != nullptr) Printnode(root->right);
    }

    template<class T>
    void Tree<T>::Printtree() {
        Printnode(this->root);
    }
}

#endif //JIMP_EXERCISES_TREE_H
