//
//  main.cpp
//  Code_04_Queue_To_Stack
//
//  Created by 陈泰文 on 2018/10/23.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

class TwoQueueStack {
    queue<int> queue0;
    queue<int> help;
    
public:
    void swap() {
        queue<int> temp = queue0;
        queue0 = help;
        help = temp;
    }
    
    void push(int i) {
        queue0.push(i);
    }
    
    int top() {
        while (queue0.size() > 1) {
            help.push(queue0.front());
            queue0.pop();
        }
        int res = queue0.front();
        queue0.pop();
        swap();
        queue0.push(res);
        return res;
    }
    
    void pop() {
        while (queue0.size() > 1) {
            help.push(queue0.front());
            queue0.pop();
        }
        queue0.pop();
        swap();
    }
};

int main() {
    TwoQueueStack stack;
    stack.push(1);
    stack.push(2);
    cout << stack.top() << endl;
    stack.push(3);
    cout << stack.top() << endl;
    stack.push(4);
    cout << stack.top() << endl;
    stack.push(5);
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    return 0;
}
