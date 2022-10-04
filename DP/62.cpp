#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0||n==0) return 1;
        int dp[m][n];
        for(int i=0; i<m; i++) {
            dp[i][0] = 1;
        }
        for(int i=0; i<n; i++) {
            dp[0][i] = 1;
        }
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout <<endl;
        // }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution *sol = new Solution();
    cout << sol->uniquePaths(3, 7);
    return 0;
}