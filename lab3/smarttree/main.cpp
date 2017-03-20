//
// Created by Grzegorz on 19.03.2017.
//
#include "SmartTree.h"
#include <iostream>
#include <ostream>
#include <string>
#include <memory>
#include <regex>
using namespace std;
using namespace datastructures;

int main(){
    unique_ptr<SmartTree> root;
    root = CreateLeaf(99);
    root = InsertLeftChild(move(root), CreateLeaf(100));
    root = InsertRightChild(move(root), CreateLeaf(88));
    root->left = InsertLeftChild(move(root->left), CreateLeaf(1234));
    root->left = InsertRightChild(move(root->left), CreateLeaf(4321));
    root->right = InsertLeftChild(move(root->right), CreateLeaf(897));
    root->right = InsertRightChild(move(root->right), CreateLeaf(761));
    cout<<DumpTree(root)<<endl;
    cout<<DumpTree(RestoreTree("[-9997 [98 [none] [none]] [99 [none] [none]]]"))<<endl;
}
