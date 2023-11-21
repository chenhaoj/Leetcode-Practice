#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MOD = 998244353;

int countSubsequences(vector<int>& arr) {
    int n = arr.size();
    vector<long long> dp(n + 1, 0);
    vector<int> lastIdx(100001, -1); // 最后出现的位置

    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = (2 * dp[i - 1]) % MOD;

        if (lastIdx[arr[i - 1]] != -1) {
            dp[i] = (dp[i] - dp[lastIdx[arr[i - 1]] - 1] + MOD) % MOD;
        }

        lastIdx[arr[i - 1]] = i - 1;
    }

    return (dp[n] - 1 + MOD) % MOD;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = countSubsequences(arr);
    cout << result << endl;

    return 0;
}
