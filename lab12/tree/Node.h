#ifndef JIMP_EXERCISES_NODE_H
#define JIMP_EXERCISES_NODE_H

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
}

#endif //JIMP_EXERCISES_NODE_H
