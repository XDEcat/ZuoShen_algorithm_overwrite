//
//  main.cpp
//  Code_01_Print_Matrix_Zig_Zag
//
//  Created by 陈泰文 on 2018/10/23.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void printDiagonal(vector<vector<int> > matrix, int row1, int col1, int row2, int col2, bool up) {
    if (up) {
        while (row2 >= row1) {
            cout << matrix[row2--][col2++] << " ";
        }
    } else {
        while (row1 <= row2) {
            cout << matrix[row1++][col1--] << " ";
        }
    }
}

void printMatrixZigZag(vector<vector<int> > matrix, int m, int n) {
    int row1 = 0;
    int col1 = 0;
    int row2 = 0;
    int col2 = 0;
    bool up = false;
    while (row1 < m) {
        printDiagonal(matrix, row1, col1, row2, col2, up);
        if (col1 != n - 1) {
            col1++;
        } else {
            row1++;
        }
        if (row2 != m - 1) {
            row2++;
        } else {
            col2++;
        }
        up = !up;
    }
    cout << endl;
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
    while (cin >> m >> n) {
        vector<vector<int> > matrix(m);
        for (int i = 0; i < m; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        printMatrix(matrix, m, n);
        printMatrixZigZag(matrix, m, n);
    }
    return 0;
}
