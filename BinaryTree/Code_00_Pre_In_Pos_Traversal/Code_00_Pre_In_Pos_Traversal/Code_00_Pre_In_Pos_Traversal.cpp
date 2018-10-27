//
//  main.cpp
//  Code_00_Pre_In_Pos_Traversal
//
//  Created by 陈泰文 on 2018/10/25.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class BitNode {
public:
    int value;
    BitNode* left;
    BitNode* right;
    
    BitNode() {
        value = 0;
        left = nullptr;
        right = nullptr;
    }
    
    BitNode(int i) {
        value = i;
        left = nullptr;
        right = nullptr;
    }
    
    ~BitNode() {}
};

BitNode* construct() {
    BitNode* root = nullptr;
    int i;
    while (cin >> i && i != -1) {
        root = new BitNode(i);
        root -> left = construct();
        root -> right = construct();
        return root;
    }
    return root;
}

void preOrderRecursion(BitNode* root) {
    if (root != nullptr) {
        cout << root -> value << " ";
        preOrderRecursion(root -> left);
        preOrderRecursion(root -> right);
    }
}

void inOrderRecursion(BitNode* root) {
    if (root != nullptr) {
        inOrderRecursion(root -> left);
        cout << root -> value << " ";
        inOrderRecursion(root -> right);
    }
}

void posOrderRecursion(BitNode* root) {
    if (root != nullptr) {
        posOrderRecursion(root -> left);
        posOrderRecursion(root -> right);
        cout << root -> value << " ";
    }
}

void preOrderNonrecursion(BitNode* root) {
    if (root != nullptr) {
        stack<BitNode*> sta;
        BitNode* ptr = root;
        sta.push(ptr);
        while (!sta.empty()) {
            ptr = sta.top();
            sta.pop();
            cout << ptr -> value << " ";
            if (ptr -> right != nullptr) {
                sta.push(ptr -> right);
            }
            if (ptr -> left != nullptr) {
                sta.push(ptr -> left);
            }
        }
    }
    cout << endl;
}

void inOrderNonrecursion(BitNode* root) {
    if (root != nullptr) {
        stack<BitNode*> sta;
        BitNode* ptr = root;
        while (ptr != nullptr || !sta.empty()) {
            if (ptr != nullptr) {
                sta.push(ptr);
                ptr = ptr -> left;
            } else {
                ptr = sta.top();
                sta.pop();
                cout << ptr -> value << " ";
                ptr = ptr -> right;
            }
        }
    }
    cout << endl;
}

void posOrderNonrecursion(BitNode* root) {
    if (root != nullptr) {
        stack<BitNode*> sta;
        stack<BitNode*> help;
        BitNode* ptr = root;
        sta.push(ptr);
        while (!sta.empty()) {
            ptr = sta.top();
            sta.pop();
            help.push(ptr);
            if (ptr -> left != nullptr) {
                sta.push(ptr -> left);
            }
            if (ptr -> right != nullptr) {
                sta.push(ptr -> right);
            }
        }
        while (!help.empty()) {
            ptr = help.top();
            help.pop();
            cout << ptr -> value << " ";
        }
    }
    cout << endl;
}

void levelOrder(BitNode* root) {
    if(root != nullptr) {
        queue<BitNode*> que;
        BitNode* ptr = root;
        que.push(ptr);
        while(!que.empty()) {
            ptr = que.front();
            que.pop();
            cout << ptr ->value << " ";
            if(ptr -> left != nullptr) {
                que.push(ptr -> left);
            }
            if(ptr -> right != nullptr) {
                que.push(ptr -> right);
            }
        }
    }
    cout << endl;
}

int main()
{
    BitNode* root=construct();
    cout << "==============recursive==============" << endl;
    cout << "PreOrder: ";
    preOrderRecursion(root);
    cout << endl;
    cout << "InOrder: ";
    inOrderRecursion(root);
    cout << endl;
    cout << "PosOrder: ";
    posOrderRecursion(root);
    cout << endl;
    cout << endl;
    cout << "=============unrecursive=============" << endl;
    cout << "PreOrder: ";
    preOrderNonrecursion(root);
    cout << "InOrder: ";
    inOrderNonrecursion(root);
    cout << "PosOrder: ";
    posOrderNonrecursion(root);
    cout << "LevelOrder: ";
    levelOrder(root);
    return 0;
}
