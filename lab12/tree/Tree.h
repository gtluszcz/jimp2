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
    Node<T>::Node(T value){
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        this->value = value;
        this->key = 12;
    }

    template<class T>
    class Tree {
    public:
        Tree();
        Tree(T value);
        void Addchild(T value);
        void Search(T value);
        void Printnode(Node<T>* root);
        void Printtree();
        int Size();
        T Value();
        void Insert(T value);
        Node<T> * root;

        int size;
    };

    template<class T>
    Tree<T>::Tree() {
        this->root = nullptr;
        size = 0;
    }

    template<class T>
    Tree<T>::Tree(T value) {
        Node<T> newnode {value};
        this->root = &newnode;
        size = 1;
    }

    template<class T>
    T Tree<T>::Value() {
        std::cout << "#" << root->value << "#";
        return root->value;
    }

    template<class T>
    int Tree<T>::Size() {
        return size;
    }

    template<class T>
    void Tree<T>::Insert(T value) {
       Addchild(value);
    }

    template<class T>
    void Tree<T>::Addchild(T value) {
        std::cout << "$" << root->value << "$";
        Node<T> newnode {value};

        if (this->root == nullptr) {
            this->root = &newnode;
            newnode.parent = nullptr;
        } else {
            Node<T>* searchnode = this->root;

            if (searchnode->left == nullptr && searchnode->right == nullptr) {
                std::cout << newnode.value << "|" << root->value;
                if (newnode.value < searchnode->value) {
                    std::cout << "HELLO WORLD!!";
                    searchnode->left = &newnode;
                } else {
                    searchnode->right = &newnode;
                }
            } else {
                while (searchnode->left != nullptr || searchnode->right != nullptr) {
                    if (newnode.value < searchnode->value) {
                        if (searchnode->left != nullptr) {
                            searchnode = searchnode->left;
                        } else {
                            newnode.parent = searchnode;
                            searchnode->left = &newnode;
                        }
                    } else if (newnode.value >= searchnode->value) {
                        if (searchnode->right != nullptr) {
                            searchnode = searchnode->right;
                        } else {
                            newnode.parent = searchnode;
                            searchnode->right = &newnode;
                        }
                    }
                }
            }
        }

        size++;
    }

    template<class T>
    void Tree<T>::Search(T value) {
        //...
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
