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
    //cout<<DumpTree(root);

    regex pattern {R"(\[{1}(\d*)\s*)"};
    string line = {"[99 "};
    smatch matches;
    if (regex_match(line, matches, pattern)) {
        cout<<"udało się dopasować do linii: "<<line<<endl;
        cout<<"zerowa grupa przechwytująca to całe dopasowanie: "<<matches[0]<<endl;
        cout<<"pierwsza grupa przechwytująca to napis: "<<matches[1]<<endl;
        cout<<"druga grupa przechwytująca to liczba: "<<matches[2]<<endl;
    }

}
