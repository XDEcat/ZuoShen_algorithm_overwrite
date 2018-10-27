//
//  main.cpp
//  Code_02_Get_Min_Stack
//
//  Created by 陈泰文 on 2018/10/22.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

class GetMinStack {
    stack<int> stackData;
    stack<int> stackMin;
    
public:
    int getMin() {
        return stackMin.top();
    }
    
    void push(int i) {
        if (stackMin.empty() || i < this -> getMin()) {
            stackMin.push(i);
        }
        stackData.push(i);
    }
    
    int top() {
        return stackData.top();
    }
    
    void pop() {
        if (stackData.top() == stackMin.top()) {
            stackMin.pop();
        }
        stackData.pop();
    }
};

int main() {
    GetMinStack stack;
    stack.push(5);
    cout << stack.getMin() << endl;
    stack.push(3);
    cout << stack.getMin() << endl;
    stack.push(4);
    cout << stack.getMin() << endl;
    stack.push(1);
    cout << stack.getMin() << endl;
    stack.push(2);
    cout << stack.getMin() << endl;
    stack.pop();
    cout << stack.getMin() << endl;
    stack.pop();
    cout << stack.getMin() << endl;
    stack.pop();
    cout << stack.getMin() << endl;
    stack.pop();
    cout << stack.getMin() << endl;
    
    return 0;
}
