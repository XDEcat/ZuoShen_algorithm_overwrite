//
//  main.cpp
//  Code_05_NetherlandsFlag
//
//  Created by 陈泰文 on 2018/10/21.
//  Copyright © 2018年 twchen. All rights reserved.
//

#define MAX_VALUE 3

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

int* partition(int arr[], int l, int r, int value) {
    int small = l - 1;
    int large = r + 1;
    int index = l;
    while (index < large) {
        if (arr[index] < value) {
            swap(arr, index++, ++small);
        } else if (arr[index] > value) {
            swap(arr, index, --large);
        } else {
            index++;
        }
    }
    return new int[2] {small + 1, large - 1};
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
    for (int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    while (cin >> n) {
        int* arr1 = getRandomArray(n);
        printArray(arr1, n);
        int* range = partition(arr1, 0, n-1, MAX_VALUE >> 1);
        printArray(arr1, n);
        cout << range[0] << " " << range[1] << endl;
    }
    return 0;
}
