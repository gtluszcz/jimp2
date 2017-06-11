#include "Node.h"

namespace tree {
    template<class T>
    Node<T>::Node(T value) {
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        this->value = value;
        this->key = (int) value;
    }
}
