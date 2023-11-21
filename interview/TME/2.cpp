#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
long long MOD = 1e9+7;
int n;
long long dp[100005][2][2][2][8];

long long calc(int i, bool r, bool e, bool d, int f) {
    // cout << " i=" << i << " r=" << r << " e=" << e << " d=" << d << " f=" << f << endl;
    if(i >= n) return d;
    if(dp[i][r][e][d][f] != -1) return dp[i][r][e][d][f];
    long long ans = 0;
    // 填r
    ans = (ans + calc(i+1, true, e, d, 1)) % MOD;
    // 填e
    int nf = 2;
    if(f == 1) nf = 3;
    ans = (ans + calc(i+1, r, r, d, nf)) % MOD;
    // 填d
    if(f != 3)
        ans = (ans + calc(i+1, r, e, r && e, 4)) % MOD;
    dp[i][r][e][d][f] = ans;
    // cout << "这种情况下: i=" << i << " r=" << r << " e=" << e << " d=" << d << " f=" << f << " ans=" << ans << endl;
    return ans;
}

int main() {
    cin >> n;
    if(n <= 3) return 0;
    memset(dp, -1, sizeof(dp));
    cout << calc(0, false, false, false, 0) << endl;
    return 0;
}