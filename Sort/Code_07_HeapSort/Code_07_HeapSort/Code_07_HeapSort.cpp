//
//  main.cpp
//  Code_07_HeapSort
//
//  Created by 陈泰文 on 2018/10/21.
//  Copyright © 2018年 twchen. All rights reserved.
//

#define MAX_VALUE 10

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heapInsert(int arr[], int index) {
    while (arr[index] > arr[(index - 1) / 2]) {
        swap(arr, index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

void heapify(int arr[], int e) {
    int index = 0;
    int left = index * 2 + 1;
    while (left <= e) {
        int largest = left + 1 <= e && arr[left] < arr[left + 1] ? left + 1 : left;
        largest = arr[index] < arr[largest] ? largest : index;
        if (largest == index) {
            break;
        }
        swap(arr, index, largest);
        index = largest;
        left = index * 2 + 1;
    }
}

void heapSort(int arr[], int len) {
    if (arr == nullptr || len < 2) {
        return;
    }
    for (int i = 0; i < len; i++) {
        heapInsert(arr, i);
    }
    int e = len - 1;
    while (e > 0) {
        swap(arr, 0, e--);
        heapify(arr, e);
    }
}

int* getRandomArray(int n) {
    int* arr = new int[n];
    srand((unsigned)time(nullptr));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
    return arr;
}

int* copyArray(int arr[], int len) {
    if (arr == nullptr) {
        return nullptr;
    }
    int* res = new int[len];
    for (int i = 0; i < len; i++) {
        res[i] = arr[i];
    }
    return res;
}

void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    while (cin >> n) {
        int* arr1 = getRandomArray(n);
        int* arr2 = copyArray(arr1, n);
        printArray(arr1, n);
        heapSort(arr1, n);
        sort(arr2, arr2 + n);
        printArray(arr1, n);
        printArray(arr2, n);
    }
    return 0;
}

