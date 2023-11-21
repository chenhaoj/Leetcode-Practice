// #include<iostream>
// using namespace std;
// const int MOD = 1000000007;
// int fi(int n) {
//     int maxDigit = 0;
//     // 计算长度
//     int nn = n;
//     int len = 0;
//     while(nn) {
//         len++;
//         int curr_digit = nn % 10;
//         // cout << curr_digit << " ";
//         nn /= 10;
//         maxDigit = max(maxDigit, curr_digit);
//     }
//     return maxDigit;
// }

// int main() {
//     int l, r;
//     cin >> l >> r;
//     int sum = 0;
//     // cout << fi(l) << endl;
//     for(int i = l; i <= r; i++) {
//         sum += fi(i);
//         sum %= MOD;
//     }
//     cout << sum << endl;
//     return 0;
// }

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
    int num;
    cin >> num;
    long long nk = 1; // n^k
    int ans = 0;
    while(num >= nk) {
        ans += (num / (nk * 10)) * nk + min(max(num % (nk * 10) - nk + 1, 0ll), nk);
        // ans += (num / (nk * 10)) * nk + min(nk, max(num % (nk * 10) - nk + 1, 0LL));
        nk *= 10;
    }
    cout << ans << endl;
    return 0;
}