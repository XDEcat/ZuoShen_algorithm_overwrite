//
//  main.cpp
//  Code_01_Paper_Folding
//
//  Created by 陈泰文 on 2018/10/25.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include <iostream>

using namespace std;

void printProcess(int i, int N, bool down) {
    if (i > N) {
        return;
    }
    printProcess(i + 1, N, true);
    cout << (down ? "down " : "up ");
    printProcess(i + 1, N, false);
}

void printAllFolding(int N) {
    printProcess(1, N, true);
    cout << endl;
}

int main() {
    int N;
    while (cin >> N) {
        printAllFolding(N);
    }
    return 0;
}
