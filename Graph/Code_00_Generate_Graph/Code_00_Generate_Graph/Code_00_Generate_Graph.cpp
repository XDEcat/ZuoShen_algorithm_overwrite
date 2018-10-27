//
//  main.cpp
//  Code_00_Generate_Graph
//
//  Created by 陈泰文 on 2018/10/25.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Edge;

class Node {
public:
    int value;
    int in;     // how many nodes point to current node
    int out;    // current node points to how many nodes
    list<Node*> nexts;   // only next node
    list<Edge> edges;   // only next edge

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

class EdgeHash {    //  custom hash function
public:
    size_t operator()(const Edge& e) const {    // override operator()
        return hash<int>() (e.weight) ^ (hash<int>() (e.from -> value) << 1) ^ (hash<int>() (e.to -> value) << 2);
    }
};

class EdgeEqual {   // custom equal function
public:
    bool operator()(const Edge& e1, const Edge& e2) const {     // override operate()
        return e1.weight == e2.weight && e1.from -> value == e2.from -> value && e1.to -> value == e2.to -> value;
    }
};

class Graph {
public:
    unordered_map<int, Node*> nodes;
    unordered_set<Edge, EdgeHash, EdgeEqual> edges;     // key(Edge) is a class(custom type),
};                                                      // so custom hash function and equal function must be given !!!
                                                        // if map/set, comparator of key must be given.
Graph construct(vector<vector<int> > matrix) {
    Graph gra;
    for (int i = 0; i < matrix.size(); i++) {
        int from = matrix[i][0];    // first is fromNode value
        int to = matrix[i][1];      // second is toNode value
        int weight = matrix[i][2];  // third is weight
        if (gra.nodes.find(from) == gra.nodes.end()) {
            Node* ptr = new Node(from);
            gra.nodes.insert({from, ptr});
        }
        if (gra.nodes.find(to) == gra.nodes.end()) {
            Node* ptr = new Node(to);
            gra.nodes.insert({to, ptr});
        }
        Node* fromNode = gra.nodes[from];
        Node* toNode = gra.nodes[to];
        Edge edge(weight, fromNode, toNode);
        fromNode -> out++;
        toNode -> in++;
        fromNode -> nexts.push_back(toNode);
        fromNode -> edges.push_back(edge);
        gra.edges.insert(edge);
    }
    return gra;
}

int main() {
    return 0;
}
