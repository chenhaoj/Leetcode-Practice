#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define PR(x) cout << #x"=" << x << endl; 

/* // 经典C++写法
static int uniquePaths(int* arr, int row, int col, int m, int n) {
    if(row <= 0 || col <= 0)
        return 0;
    
    // 初始化
    int dp[3][3] = {0};
    dp[0][0] = *(arr);
    for(int j = 1; j < 3; j++) {
        dp[0][j] = dp[0][j-1] + *(arr+j);
    };
    for(int i = 1; i < 3; i++) {
        dp[i][0] = dp[i-1][0] + *(arr+i*col);
    }
    // 关系式
    for(int i = 1; i < 3; i++) {
        for(int j = 1; j < 3; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + *(arr+i*col+j);
        }
    }
    return dp[m][n];
} */

/* vector写法 */
static int uniquePaths(vector<vector<int> >& arr) {
    int row = arr.size(), col = arr[0].size();

    // 初始化
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(i == 0 && j != 0) {
                arr[0][j] += arr[0][j-1];
            }
            else if(j == 0 && i != 0) {
                arr[i][0] += arr[i-1][0];
            }
            else if(i > 0 && j > 0) {
                arr[i][j] += min(arr[i-1][j], arr[i][j-1]);
            }
        }
    }
    return arr[row-1][col-1];
}

int main() {
    // int arr[3][3] = {1,3,1,1,5,1,4,2,1};
    // int elements = sizeof(arr)/sizeof(arr[0][0]);
    // int row = sizeof(arr)/sizeof(arr[0]);
    // int column = elements/row;
    // cout << uniquePaths(*arr, row, column, 2, 2) << endl;
    vector<vector<int> > arr{{1,3,1},{1,5,1},{4,2,1}};
    cout << uniquePaths(arr) << endl;
    return 0;
}