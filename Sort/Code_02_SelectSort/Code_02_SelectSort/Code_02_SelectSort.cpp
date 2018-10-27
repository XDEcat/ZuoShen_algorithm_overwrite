//
//  main.cpp
//  Code_02_SelectSort
//
//  Created by 陈泰文 on 2018/10/20.
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

void selectSort(int arr[], int len) {
    if (arr == nullptr || len < 2) {
        return;
    }
    for (int i = 0; i < len - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < len; j++) {
            minIndex = arr[j] < arr[minIndex] ? j : minIndex;
        }
        swap(arr, i, minIndex);
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
    for (int i = 0; i < len; i++){
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
        selectSort(arr1, n);
        sort(arr2, arr2 + n);
        printArray(arr1, n);
        printArray(arr2, n);
    }
    return 0;
}
