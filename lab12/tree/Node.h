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
}

#endif //JIMP_EXERCISES_NODE_H
