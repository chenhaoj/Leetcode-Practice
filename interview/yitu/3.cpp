#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, K, d;
    cin >> n >> K >> d;
    vector<int> ai;
    while(n--) {
        int a;
        cin >> a;
        ai.push_back(a); 
    }
    
    // dp[k][i]: 选中了k个学生并以第i个学生结尾时的最大乘积
    int res = INT_MIN;
    vector<vector<int> > dp_max(K+1, vector<int>(ai.size()+1, INT_MIN));
    vector<vector<int> > dp_min(K+1, vector<int>(ai.size()+1, INT_MAX));
    for(int i = 1; i <= ai.size(); i++) {
        dp_max[1][i] = dp_min[1][i] = ai[i-1];
        for(int k = 2; k <= K; k++) {
            for(int j = i-1; j >= k-1 && i-j <= d; j--) {
                dp_max[k][i] = max(dp_max[k][i], max(dp_max[k-1][j]*ai[i-1], dp_min[k-1][j]*ai[i-1]));
                dp_min[k][i] = min(dp_min[k][i], max(dp_max[k-1][j]*ai[i-1], dp_min[k-1][j]*ai[i-1]));
                // cout << dp_max[k][i] << " " << dp_min[k][i] << endl;
            }
        }
        res = max(res, dp_max[K][i]);
    }
    cout << res << endl;
    return 0;
}