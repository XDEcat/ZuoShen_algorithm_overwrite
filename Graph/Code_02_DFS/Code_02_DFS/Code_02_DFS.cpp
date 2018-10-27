//
//  main.cpp
//  Code_02_DFS
//
//  Created by 陈泰文 on 2018/10/27.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include <iostream>
#include <list>
#include <stack>
#include <unordered_set>

using namespace std;

class Edge;

class Node {
public:
    int value;
    int in;
    int out;
    list<Node*> nexts;
    list<Edge> edges;
    
    Node() {}
    
    Node(int value) {
        this -> value = value;
        in = 0;
        out = 0;
    }
    
    ~Node() {}
};

class Edge {
public:
    int weight;
    Node* from;
    Node* to;
    
    Edge() {}
    
    Edge(int weight, Node* from, Node* to) : weight(weight), from(from), to(to) {}
    
    ~Edge() {}
};

void dfs(Node* node) {
    if (node == nullptr) {
        return;
    }
    stack<Node*> sta;
    unordered_set<int> visited;
    sta.push(node);
    visited.insert(node -> value);
    while (!sta.empty()) {
        Node* ptr = sta.top();
        sta.pop();
        cout << ptr -> value;
        for (Node* next : ptr -> nexts) {
            if (visited.find(next -> value) == visited.end()) {
                sta.push(next);
                visited.insert(next -> value);
            }
        }
    }
}

int main() {
    return 0;
}

