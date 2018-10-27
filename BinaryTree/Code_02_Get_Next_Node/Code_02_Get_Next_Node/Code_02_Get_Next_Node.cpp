//
//  main.cpp
//  Code_02_Get_Next_Node
//
//  Created by 陈泰文 on 2018/10/25.
//  Copyright © 2018年 twchen. All rights reserved.
//
//  Find the next node in inorder.

#include <iostream>

using namespace std;

class BitNode {
public:
    int value;
    BitNode* left;
    BitNode* right;
    BitNode* parent;    // root -> parent = nullptr
    
    BitNode() {
        value = 0;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
    
    BitNode(int i) {
        value = i;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
    
    ~BitNode() {}
};

BitNode* getLeftMost(BitNode* node) {
    while (node -> left != nullptr) {
        node = node -> left;
    }
    return node;
}

BitNode* getNextNode(BitNode* node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node -> right != nullptr) { // if node has right tree, next node is the most left node of the right tree
        return getLeftMost(node -> right);
    } else {    // if not, find the first node which is someone's left, return someone
        BitNode* par = node -> parent;
        while (node != par -> left && par != nullptr) {
            node = par;
            par = par -> parent;
        }
        return par;
    }
}

int main() {
    return  0;
}
