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
    vector<int> array{1,2,3,4,5};
    vector<int> array_swap{6,7,8};
    // array_swap.swap(array);
    array_swap.assign(array.begin(), array.end()); // 
    for(auto& x: array_swap) {
        cout << x << " ";
    }
    cout << endl;
    for(auto& x: array) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}