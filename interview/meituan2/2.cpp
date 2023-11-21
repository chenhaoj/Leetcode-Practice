#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int minStringValue(string s, int k) {
    int n = s.length();
    vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] + (s[i - 1] == '0' ? 1 : 0);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (s[i - 1] == '0') {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + 1);
            } else {
                dp[i][j] = max(dp[i - 1][j] + 1, dp[i - 1][j - 1]);
            }
        }
    }

    return n - dp[n][k];
}

int main() {
    string s = "11";
    int k = 1;
    int result = minStringValue(s, k);
    cout << result << endl;  // 输出2

    return 0;
}
