//
//  main.cpp
//  Code_01_Array_To_Queue
//
//  Created by 陈泰文 on 2018/10/22.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include <iostream>

using namespace std;

class ArrayQueue {
    int* arr;
    int array_size;
    int p_front;
    int p_back;
    int size;
    
public:
    ArrayQueue(int ArraySize) : arr(new int[ArraySize]), array_size(ArraySize), p_front(0), p_back(0), size(0) {
        cout << "Construct a queue using an array of a constant size = " << ArraySize << endl;
    }
    
    ~ArrayQueue() {
        delete [] arr;
        cout << "Destruct queue" << endl;
    }
    
    void push(int i) {
        try {
            if (size == array_size) {
                throw "The stack is full";
            }
            arr[p_back] = i;
            p_back = p_back == array_size - 1 ? 0 : p_back + 1;
            size++;
        } catch (const char* e) {
            cout << e << endl;
        }
    }
    
    int front() {
        try {
            if (size == 0) {
                throw "The stack is empty";
            }
            return arr[p_front];
        } catch (const char* e) {
            cout << e << endl;
            return -1;
        }
    }
    
    int back() {
        try {
            if (size == 0) {
                throw "The stack is empty";
            }
            int temp = p_back == 0 ? array_size - 1 : p_back - 1;
            return arr[temp];
        } catch (const char* e) {
            cout << e << endl;
            return -1;
        }
    }
    
    void pop() {
        try {
            if (size == 0) {
                throw "The stack is empty";
            }
            p_front = p_front == array_size - 1 ? 0 : p_front + 1;
            size--;
        } catch (const char* e) {
            cout << e << endl;
        }
    }
    
    void print() {
        if (p_front < p_back) {
            for (int i = p_front; i < p_back; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        } else if (p_front > p_back) {
            for (int i = p_front; i < array_size; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i < p_back; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        } else {
            if (size == array_size) {
                for (int i = p_front; i < array_size; i++) {
                    cout << arr[i] << " ";
                }
                for (int i = 0; i < p_back; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
            } else {
                cout << endl;
            }
        }
    }
    
    int getQueueSize() {
        return size;
    }
};

int main() {
    int n;
    cin >> n;
    ArrayQueue ArrayQueue(n);
    cout << ArrayQueue.front() << endl;
    ArrayQueue.pop();
    int i;
    while (cin >> i) {
        ArrayQueue.push(i);
    }
    ArrayQueue.print();
    while (ArrayQueue.getQueueSize() > 0) {
        cout << ArrayQueue.front() << endl;
        ArrayQueue.pop();
        ArrayQueue.print();
    }
    cout << ArrayQueue.front() << endl;
    ArrayQueue.pop();
    return 0;
}
