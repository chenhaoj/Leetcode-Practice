#include <iostream>
#include <algorithm>
using namespace std;

static int minDistance(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    // int *dp = new int[m][n];
    int dp[m+1][n+1]; // 从m长串转变为n长串
    // 初始化
    dp[0][0] = 0;
    for(int j = 1; j <= n; j++) {
        dp[0][j] = dp[0][j-1] + 1; // 插入
    }
    for(int i = 1; i <= m; i++) {
        dp[i][0] = dp[i-1][0] + 1; // 删除
    }
    // 关系式
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
            }
        }
    }
    return dp[m][n];
}

int main() {
    string word1 = "horse", word2 = "ros";
    cout << minDistance(word1, word2) << endl;
    return 0;
}