#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <iostream>
namespace tree{
    template<class T>
    class Node{
    public:
        Node(T value);
        Node<T>* left;
        Node<T>* right;
        Node<T>* parent;
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
    class Tree{
    public:
        Tree();
        void Addchild(T value);
        void Search(T value);
        void Printnode(Node<T>* root);
        void Printtree();
        Node<T>* root;
    };

    template<class T>
    Tree<T>::Tree(){
        this->root= nullptr;
    }

    template<class T>
    void Tree<T>::Addchild(T value){
        Node<T> newnode = Node<T>(value);
        if(this->root==nullptr){
            this->root = &newnode;
            newnode.parent = nullptr;
        }
        else{
            Node<T>* searchnode = this->root;
            while(searchnode->left != nullptr || searchnode->right != nullptr){
                if (newnode.key < searchnode->key){
                    if (searchnode->left != nullptr){
                        searchnode = searchnode->left;
                    }
                    else{
                        newnode.parent = searchnode;
                        searchnode->left = &newnode;
                    }
                }
                else if (newnode.key >= searchnode->key){
                    if (searchnode->right != nullptr){
                        searchnode = searchnode->right;
                    }
                    else{
                        newnode.parent = searchnode;
                        searchnode->right = &newnode;
                    }
                }
            }
        }
    }

    template<class T>
    void Tree<T>::Search(T value){
        //...
    }

    template<class T>
    void Tree<T>::Printnode(Node<T>* root){
        std::cout<<root->key<<std::endl;
        if (root->left != nullptr){Printnode(root->left);}
        if (root->right != nullptr){Printnode(root->right);}
    }

    template<class T>
    void Tree<T>::Printtree(){
        Printnode(this->root);
    }

}

#endif //JIMP_EXERCISES_TREE_H
