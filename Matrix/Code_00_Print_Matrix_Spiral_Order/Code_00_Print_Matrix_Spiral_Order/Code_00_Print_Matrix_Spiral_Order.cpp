//
//  main.cpp
//  Code_00_PrintMatrixSpiralOrder
//
//  Created by 陈泰文 on 2018/10/23.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void printEdge(vector<vector<int> > matrix, int row1, int col1, int row2, int col2) {
    if (row1 == row2) {
        for (int i = col1; i <= col2; i++) {
            cout << matrix[row1][i] << " ";
        }
    } else if (col1 == col2) {
        for (int i = row1; i <= row2; i++) {
            cout << matrix[i][col1] << " ";
        }
    } else {
        for (int i = col1; i < col2; i++) {
            cout << matrix[row1][i] << " ";
        }
        for (int i = row1; i < row2 ; i++) {
            cout << matrix[i][col2] << " ";
        }
        for (int i = col2; i > col1; i--) {
            cout << matrix[row2][i] << " ";
        }
        for (int i = row2; i > row1; i--) {
            cout << matrix[i][col1] << " ";
        }
    }
}

void printMatrixSpiralOrder(vector<vector<int> > matrix, int m, int n) {
    int row1 = 0;
    int col1 = 0;
    int row2 = m-1;
    int col2 = n-1;
    while (row1 <= row2 && col1 <= col2) {
        printEdge(matrix, row1++, col1++, row2--, col2--);
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
        printMatrixSpiralOrder(matrix, m, n);
    }
    return 0;
}
