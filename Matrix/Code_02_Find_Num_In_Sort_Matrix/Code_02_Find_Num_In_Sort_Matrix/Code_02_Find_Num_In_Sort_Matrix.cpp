//
//  main.cpp
//  Code_02_Find_Num_In_Sort_Matrix
//
//  Created by 陈泰文 on 2018/10/24.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool findNumInSortMatrix(vector<vector<int> > matrix, int m, int n, int num) {
    int row = 0;
    int col = n - 1;
    while (row < m && col >=0) {
        if (matrix[row][col] == num) {
            return true;
        } else if (matrix[row][col] < num) {
            row++;
        } else {
            col--;
        }
    }
    return false;
}

void printMatrix(vector<vector<int> > matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int> > matrix(m);
    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    printMatrix(matrix, m, n);
    int num;
    cout << "Input num: ";
    while (cin >> num) {
        if (findNumInSortMatrix(matrix, m, n, num)) {
            cout << num << " is in the matrix." << endl;
        } else {
            cout << num << " is not in the matrix." << endl;
        }
    }
    return 0;
}
