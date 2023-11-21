#include<iostream>
#include<vector>
using namespace std;

// using ll = long long;
#define MOD 1e9+7

vector<int> dp;
int calc(int n) {
    if(n % 2 == 0 || n < 0) return 0;
    if(n == 1) return 1;
    long long ans = 0;
    for(int i = 1; i < n; i++) {
        long long a = calc(i);
        long long b = calc(n - i - 1);
        ans = (ans + a * b) % 1000000007;
    }
    dp[n] = ans;
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    dp.resize(n, 0);
    int ans = calc(n);
    cout << ans << endl;
    return 0;
}