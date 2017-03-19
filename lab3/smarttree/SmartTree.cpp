//
// Created by Grzegorz on 19.03.2017.
//

#include "SmartTree.h"
#include <iostream>
#include <ostream>
#include <string>
#include <memory>
#include <regex>

namespace datastructures {

    std::unique_ptr<SmartTree> CreateLeaf(int value){
        SmartTree leaf = {value, nullptr, nullptr};
        auto newleaf = std::make_unique<SmartTree>(std::move(leaf));
        return newleaf;
    }

    std::unique_ptr<SmartTree>
    InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
        tree->left = move(left_subtree);
        return tree;
    }

    std::unique_ptr<SmartTree>
    InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        tree->right = move(right_subtree);
        return tree;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        if (unique_ptr->left != nullptr){
            PrintTreeInOrder(unique_ptr->left, out);
        }
        (*out)<<unique_ptr->value<<", ";
        if (unique_ptr->right != nullptr){
            PrintTreeInOrder(unique_ptr->right, out);
        }
    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree){
        std::string dump;
        std::cout<<dump<<std::endl;
        dump+="[";
        dump+=std::to_string(tree->value);
        dump+=" ";
        if (tree->left != nullptr){
            dump+=DumpTree(tree->left);
        }
        else{
            dump+="[none]";
        }
        dump+=" ";
        if (tree->right != nullptr){
            dump+=DumpTree(tree->right);
        }
        else{
            dump+="[none]";
        }
        dump+="]";
        return dump;
    }

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree){
        //std::regex pattern {R"((\d*)\s([.*])\s([.*]))"};

    }
}