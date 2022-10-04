#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string> > dp(n+1);
        dp[0] = { "" };
        dp[1] = { "()" };
        // cout << dp[1].size();
        for(int i = 2; i <= n; i++) {
            // cout << "i=" << i << endl;
            for(int j = 0; j < i; j++) {
                // cout << "i=" << i << "j=" << j << endl;
                string str;
                // cout << i-1-j << ":" << dp[i-1-j].size() << endl;
                for(int p = 0; p < dp[j].size();p++) {
                    for(int q = 0; q < dp[i-1-j].size(); q++){
                        // cout << "i=" << i << " j=" << j << " p=" << p << " dp[" << j << "]=" << dp[j].size() << " q=" << q << " dp[" << i-1-j << "]=" << dp[i-1-j].size() << endl;
                        str = "(" + dp[j][p] + ")" + dp[i-1-j][q];
                        dp[i].push_back(str);
                    }
                }
                // for(string p:dp[j]) {
                //     for(string q: dp[i-1-j]) {
                //         str = "(" + p + ")" + q;
                //         dp[i].push_back(str);
                //     }
                // }
            }
        }
        // for(int i = 0; i <= 1; i++) {
        //     cout << dp[0][0] << endl;
        // }
        // cout << dp[3].size() << endl;
        for(int i = 0; i <= n; i++) {
            for(string j : dp[i]) {
                cout << j << "、";
            }
            cout << endl;
        }
        return dp[n];
    }
};

int main() {
    Solution *sol = new Solution();
    sol->generateParenthesis(3);
    return 0;
}