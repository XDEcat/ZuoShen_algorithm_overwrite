//
//  main.cpp
//  Code_03_MergeSort
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

void merge(int arr[], int l, int mid, int r) {
    int* help = new int[r - l + 1];
    int index = 0;
    int p1 = l;
    int p2 = mid + 1;
    while (p1 <= mid && p2 <= r) {
        help[index++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
    }
    while (p1 <= mid) {
        help[index++] = arr[p1++];
    }
    while (p2 <= r) {
        help[index++] = arr[p2++];
    }
    for (index = 0; index < r - l + 1; index++) {
        arr[l + index] = help[index];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l == r) {
        return;
    }
    int mid = l + ((r - l) >> 1);
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

void mergeSort(int arr[], int len) {
    if (arr == nullptr || len < 2) {
        return;
    }
    mergeSort(arr, 0, len - 1);
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
        mergeSort(arr1, n);
        sort(arr2, arr2 + n);
        printArray(arr1, n);
        printArray(arr2, n);
    }
    return 0;
}
