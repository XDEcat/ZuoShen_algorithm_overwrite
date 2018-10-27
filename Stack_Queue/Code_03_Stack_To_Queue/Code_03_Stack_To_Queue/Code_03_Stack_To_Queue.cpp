//
//  main.cpp
//  Code_03_Stack_To_Queue
//
//  Created by 陈泰文 on 2018/10/23.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class TwoStackQueue {
    stack<int> stack_push;
    stack<int> stack_pop;
    
public:
    void push(int i) {
        stack_push.push(i);
    }
    
    int front() {
        if (!stack_pop.empty()) {
            return stack_pop.top();
        } else {
            while (!stack_push.empty()) {
                stack_pop.push(stack_push.top());
                stack_push.pop();
            }
            return stack_pop.top();
        }
    }
    
    void pop() {
        if (!stack_pop.empty()) {
            stack_pop.pop();
        } else {
            while (!stack_push.empty()) {
                stack_pop.push(stack_push.top());
                stack_push.pop();
            }
            stack_pop.pop();
        }
    }
};

int main() {
    TwoStackQueue queue;
    queue.push(1);
    queue.push(2);
    cout << queue.front() << endl;
    queue.push(3);
    cout << queue.front() << endl;
    queue.push(4);
    cout << queue.front() << endl;
    queue.push(5);
    cout << queue.front() << endl;
    queue.pop();
    cout << queue.front() << endl;
    queue.pop();
    cout << queue.front() << endl;
    queue.pop();
    cout << queue.front() << endl;
    queue.pop();
    cout << queue.front() << endl;
    return 0;
}
