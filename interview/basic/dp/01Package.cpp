#include<iostream>
#include<vector>
using namespace std;

int getMaxValue(int bagWeight, vector<int>& weight, vector<int>& value) {
    vector<int> dp(weight.size()+1, 0);
    // // 01背包
    // for(int i = 0; i < weight.size(); i++) {
    //     for(int j = bagWeight; j >= weight[i]; j--) {
    //         dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
    //     }
    // }
    // return dp[bagWeight];
    // 完全背包
    for(int i = 0; i < weight.size(); i++) {
        for(int j = 0; j <= bagWeight; j++) {
            // int y = j - weight[i] >= 0 ? dp[j - weight[i]] + value[i] : 0;
            dp[j] = max(dp[j], j-weight[i]>=0?dp[j-weight[i]]+value[i]:0);
        }
    }
    return dp[bagWeight];
    // 完全背包
    // vector<vector<int> > dp(2, vector<int>(bagWeight+1, 0));
    // for(int j = 0; j <= bagWeight; j++) {
    //     int maxK = j / weight[0];
    //     dp[0][j] = maxK * value[0];
    // }
    // for(int i = 1; i < weight.size(); i++) {
    //     for(int j = 0; j <= bagWeight; j++) {
    //         int y = 0;
    //         for(int k = 1;;k++) { // 确定当前物品选几个
    //             if(j < k*weight[i]) {
    //                 break;
    //             }
    //             y = max(y, dp[(i-1)%2][j-k*weight[i]]+k*value[i]);
    //         }
    //         dp[i%2][j] = max(dp[(i-1)%2][j], y);
    //     }
    // }
    // return dp[(weight.size()-1)%2][bagWeight];
}

int main() {
    int m, n = 0;
    cin >> m >> n;
    vector<int> weight(m, 0);
    vector<int> value(m, 0);
    for(int i = 0; i < m; i++) {
        int w, v = 0;
        cin >> w >> v;
        weight[i] = w;
        value[i] = v;
    }
    int res = 0;
    res = getMaxValue(n, weight, value);
    cout << res << endl;
    return 0;
}