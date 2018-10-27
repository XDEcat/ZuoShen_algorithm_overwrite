//
//  main.cpp
//  Code_00_Array_To_Stack
//
//  Created by 陈泰文 on 2018/10/21.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include <iostream>

using namespace std;

class ArrayStack {
    int* arr;
    int array_size;
    int index;
    
public:
    ArrayStack(int ArraySize) : arr(new int[ArraySize]), array_size(ArraySize), index(0) {
        cout << "Construct a stack using an array of a constant size = " << ArraySize << endl;
    }
    
    ~ArrayStack() {
        delete [] arr;
        cout << "Destruct stack" << endl;
    }
    
    void push(int i) {
        try {
            if (index == array_size) {
                throw "The stack is full";
            }
            arr[index++] = i;
        } catch (const char* e) {
            cout << e << endl;
        }
    }
    
    int top() {
        try {
            if (index == 0) {
                throw "The stack is empty";
            }
            return arr[index - 1];
        } catch (const char* e) {
            cout << e << endl;
            return -1;
        }
    }
    
    void pop() {
        try {
            if (index == 0) {
                throw "The stack is empty";
            }
            index--;
        } catch (const char* e) {
            cout << e << endl;
        }
    }
    
    void print() {
        for (int i = 0; i < index; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    int getStackSize() {
        return index;
    }
};

int main() {
    int n;
    cin >> n;
    ArrayStack ArrayStack(n);
    cout << ArrayStack.top() << endl;
    ArrayStack.pop();
    int i;
    while (cin >> i) {
        ArrayStack.push(i);
    }
    cin.clear();
    cin.sync();
    ArrayStack.print();
    while (ArrayStack.getStackSize() > 0) {
        cout << ArrayStack.top() << endl;
        ArrayStack.pop();
        ArrayStack.print();
    }
    cout << ArrayStack.top() << endl;
    ArrayStack.pop();
    return 0;
}
