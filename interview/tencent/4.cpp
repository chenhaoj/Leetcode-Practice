#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int MOD = 10e9+7;
int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        ans = pow(2, n-k) - 1 % MOD;
        cout << ans << endl;
    }
    return 0;
}