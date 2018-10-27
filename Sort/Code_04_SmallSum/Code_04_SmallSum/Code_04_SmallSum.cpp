//
//  main.cpp
//  SmallSum
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

int merge(int arr[], int l, int mid, int r) {
    int* help = new int[r - l + 1];
    int index = 0;
    int p1 = l;
    int p2 = mid + 1;
    int res = 0;
    while (p1 <= mid && p2 <= r) {
        res += arr[p1] <= arr[p2] ? arr[p1] * (r - p2 + 1) : 0;
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
    return res;
}

int mergeSort(int arr[], int l, int r) {
    if (l == r) {
        return 0;
    }
    int mid = l + ((r - l) >> 1);
    return mergeSort(arr, l, mid) + mergeSort(arr, mid + 1, r) + merge(arr, l, mid, r);
}

int smallSum(int arr[], int len) {
    if (arr == nullptr || len < 2) {
        return 0;
    }
    return mergeSort(arr, 0, len - 1);
}

int comparator(int arr[], int len) {
    int res = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            res += arr[i] <= arr[j] ? arr[i] : 0;
        }
    }
    return res;
}

int* getRandomArray(int n) {
    int* arr = new int[n];
    srand((unsigned)time(nullptr));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
    return arr;
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
        printArray(arr1, n);
        cout << comparator(arr1, n) << endl;
        cout << smallSum(arr1, n) << endl;
    }
    return 0;
}

