#include "Tree.h"

namespace tree {
    static vector<int> result;

    template<class T>
    vector<int> PreOrder(Node<T> * node) {
        if (node == nullptr) return result;

        result.push_back(node->key);
        PreOrder(node->left);
        PreOrder(node->right);

        return result;
    }

    template<class T>
    vector<int> PreOrder(Tree<T> * tree) {
        result.clear();
        return PreOrder(tree->root);
    }

    template<class T>
    vector<int> InOrder(Node<T> * node) {
        if (node == nullptr) return result;

        PreOrder(node->left);
        result.push_back(node->key);
        PreOrder(node->right);

        return result;
    }

    template<class T>
    vector<int> InOrder(Tree<T> * tree) {
        result.clear();
        return InOrder(tree->root);
    }

    template<class T>
    vector<int> PostOrder(Node<T> * node) {
        if (node == nullptr) return result;

        PreOrder(node->left);
        PreOrder(node->right);
        result.push_back(node->key);

        return result;
    }

    template<class T>
    vector<int> PostOrder(Tree<T> * tree) {
        result.clear();
        return PostOrder(tree->root);
    }

    template<class T>
    Tree<T>::Tree() {
        this->root = nullptr;
        size = 0;
    }

    template<class T>
    Tree<T>::~Tree() {
        DeleteTree(root);
    }

    template<class T>
    void Tree<T>::DeleteTree(Node<T> * node) {
        if (node == nullptr) return;

        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return;
        }

        DeleteTree(node->left);
        DeleteTree(node->right);
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
        return Depth(root);
    }

    template<class T>
    int Tree<T>::Depth(Node<T> * node) {
        if (node == nullptr) return 0;

        int lDepth = Depth(node->left);
        int rDepth = Depth(node->right);

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
        return Search(root, value);
    }

    template<class T>
    Node<T> * Tree<T>::Search(Node<T> * x, T k) {
        if (x == nullptr || k == x->key) {
            return x;
        }

        if (k < x->key) {
            return Search(x->left, k);
        } else {
            return Search(x->right, k);
        }
    }

    template<class T>
    void Tree<T>::PrintNode(Node<T> * node) {
        std::cout << node->key << std::endl;
        if (node->left != nullptr) PrintNode(node->left);
        if (node->right != nullptr) PrintNode(node->right);
    }

    template<class T>
    void Tree<T>::PrintTree() {
        PrintNode(this->root);
    }

    template<class T>
    void Tree<T>::PrintPreorder(Node<T> * node) {
        if (node == nullptr) return;

        std::cout << node->value << " ";
        PrintPreorder(node->left);
        PrintPreorder(node->right);
    }

    template<class T>
    void Tree<T>::PrintInorder(Node<T> * node) {
        if (node == nullptr) return;

        PrintPreorder(node->left);
        std::cout << node->value << " ";
        PrintPreorder(node->right);
    }

    template<class T>
    void Tree<T>::PrintPostorder(Node<T> * node) {
        if (node == nullptr) return;

        PrintPreorder(node->left);
        PrintPreorder(node->right);
        std::cout << node->value << " ";
    }

    template<class T>
    void Tree<T>::PrintPreorder() {
        PrintPreorder(root);
    }

    template<class T>
    void Tree<T>::PrintInorder() {
        PrintInorder(root);
    }

    template<class T>
    void Tree<T>::PrintPostorder() {
        PrintPostorder(root);
    }
}
