/* 连续子数组最大 */
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> ans;
    while(t-- > 0) {
        int n, x;
        cin >> n >> x;
        int i = 0;
        // 处理输入
        vector<int> array;
        int temp;
        // while(cin >> temp && cin.get() != '\n') {
        //     array.push_back(temp);
        //     // if(getchar() == '\n') {
        //     //     break;
        //     // }
        // }
        // array.push_back(temp);
        while(cin >> temp) {
            array.push_back(temp);
            // if(getchar() == '\n') {
            if(cin.get() == '\n') {
                break;
            }
        }

        // 验证
        // for(int i = 0; i < array.size(); i++) {
        //     cout << array[i] << " ";
        // }
        // cout << endl;

        // 开始处理
        int res = INT_MIN;
        // 1. 计算正向dp，前缀连续子串
        vector<int> dp1(n);
        dp1[0] = array[0];
        for(int i = 1; i < n; i++) {
            dp1[i] = max(dp1[i-1]+array[i], array[i]);
            res = max(res, dp1[i]);
        }
        // 2. 计算逆向dp，后缀连续子串
        vector<int> dp2(n);
        dp2[n-1] = array[n-1];
        for(int j = n-2; j >= 0; j--) {
            dp2[j] = max(dp2[j+1]+array[j], array[j]);
        }
        // 3. 枚举替换
        for(int i = 0; i < n; i++) {
            res = max(res, (i > 0 && dp1[i-1] > 0 ? dp1[i-1] : 0) + (i < n-1 && dp2[i+1] > 0 ? dp2[i+1] : 0) + x);
        }
        // 4. 返回最大值
        // cout << res << endl;
        ans.push_back(res);
    }
    for(auto& num:ans) {
        cout << num << endl;
    }
    return 0;
}