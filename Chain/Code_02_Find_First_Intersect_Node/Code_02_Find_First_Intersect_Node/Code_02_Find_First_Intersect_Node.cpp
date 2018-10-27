//
//  main.cpp
//  Code_02_Find_First_Intersect_Node
//
//  Created by 陈泰文 on 2018/10/24.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include <iostream>
#include <unordered_set>

using namespace std;

class Node {
public:
    int value;
    Node* next;
    
    Node() {
        value = 0;
        next = nullptr;
    }
    
    Node(int i) {
        value = i;
        next = nullptr;
    }
    
    ~Node() {}
};

//  Space: O(n)
Node* getLoopNode_hashset(Node* head) {
    unordered_set<Node*> hashset;
    Node* ptr = head;
    while (ptr != nullptr) {
        if (hashset.find(ptr) != hashset.end()) {
            return ptr;
        } else {
            ptr = ptr -> next;
        }
    }
    return nullptr;
}

//  Space: O(1)
Node* getLoopNode_fast_slow_ptr(Node* head) {
    if (head == nullptr || head -> next == nullptr || head -> next ->next == nullptr) {
        return nullptr;
    }
    Node* fast = head -> next -> next;
    Node* slow = head -> next;
    while (fast != slow) {  // if fast and slow do not meet, chain has no loop
        if (fast -> next == nullptr || fast -> next ->next == nullptr) {
            return nullptr;
        } else {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
    }
    fast = head;
    while (fast != slow) {  // fast returns head, step changes to 1, fast and slow will meet at LoopNode
        fast = fast -> next;
        slow = slow -> next;
    }
    return fast;
}

Node* noLoop(Node* head1, Node* head2) {
    if (head1 == nullptr || head2 == nullptr) {
        return nullptr;
    }
    Node* end1 = head1;
    Node* end2 = head2;
    int n = 0;
    while (end1 != nullptr) {
        n++;
        end1 = end1 -> next;
    }
    while (end2 != nullptr) {
        n--;
        end2 = end2 -> next;
    }
    if (end1 != end2) { // end1 == end2 is equal to intersect
        return nullptr;
    }
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    if (n > 0) {    // if chain1.len - chain2.len = n > 0, chain1 steps n, then two chain step together
        while (n != 0) {
            ptr1 = ptr1 -> next;
            n--;
        }
    } else {
        while (n != 0) {
            ptr2 = ptr2 -> next;
            n++;
        }
    }
    while (ptr1 != ptr2) {
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }
    return ptr1;
}

Node* bothLoop(Node* head1, Node* head2, Node* loop1, Node* loop2) {
    if (loop1 == loop2) {   // 1. is equal to the problem of noLoop with chains end up with loop1/loop2
        Node* end1 = head1;
        Node* end2 = head2;
        int n = 0;
        while (end1 != loop1) {
            n++;
            end1 = end1 -> next;
        }
        while (end2 != loop2) {
            n--;
            end2 = end2 -> next;
        }
        Node* ptr1 = head1;
        Node* ptr2 = head2;
        if (n > 0) {
            while (n != 0) {
                ptr1 = ptr1 -> next;
                n--;
            }
        } else {
            while (n != 0) {
                ptr2 = ptr2 -> next;
                n++;
            }
        }
        while (ptr1 != ptr2) {
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        return ptr1;
    } else {    // 2. form loop1 -> next, loop1 steps forward before returning loop1 again, if passing by loop2, intersect
        Node* ptr = loop1 -> next;
        while (ptr != loop1) {
            if (ptr == loop2) {
                return loop1;   // loop1/loop2 all correct
            }
            ptr = ptr -> next;
        }
        return nullptr; //3. if not passing by loop2, do not intersect
    }
}

Node* getIntersectNode(Node* head1, Node* head2) {
    if (head1 == nullptr || head2 == nullptr) {
        return nullptr;
    }
    Node* loop1 = getLoopNode_fast_slow_ptr(head1);
    Node* loop2 = getLoopNode_fast_slow_ptr(head2);
    if (loop1 == nullptr && loop2 == nullptr) {
        return noLoop(head1, head2);
    }
    if (loop1 != nullptr && loop2 != nullptr) {
        return bothLoop(head1, head2, loop1, loop2);
    }
    return nullptr; // if one has loop, the other one does not, can not intersect
}

int main() {
    return 0;
}
