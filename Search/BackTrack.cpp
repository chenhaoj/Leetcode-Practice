/**
 * @file BackTrack.cpp
 * @author your name (you@domain.com)
 * @brief 回溯经典问题之 “八皇后”
 * @version 0.1
 * @date 2022-08-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;
#define QUEEN_SIZE 8 // N皇后
int place[QUEEN_SIZE] = {0}; // place[i]=j表示第(i+1)行的皇后放在第(j+1)列，如place[3]=2表示第4行皇后放第3列
int flag[QUEEN_SIZE] = {1,1,1,1,1,1,1,1}; // 列标签{1,1,1,1,1,1,1,1}
int diagonal_1[1+QUEEN_SIZE*2] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; // 上对角线
int diagonal_2[1+QUEEN_SIZE*2] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; // 下对角线
int nums = 0; // 可行解数

int numOfQueen(int n) {
    for(int col = 0; col < 8; col++) {
        if(flag[col] && diagonal_1[n-col+7] && diagonal_2[n+col]) {
            // place[n] = col;
            flag[col] = false;
            diagonal_1[n-col+7] = false;
            diagonal_2[n+col] = false;
            if(n<7) {
                numOfQueen(n+1);
            }
            else {
                nums++;
            }
            // place[n] = 0;
            flag[col] = true;
            diagonal_1[n-col+7] = true;
            diagonal_2[n+col] = true;
        }
    }
    return nums;
}

int main() {
    cout << numOfQueen(0) << endl;
    return 0;
}