// #include <iostream>
// using namespace std;

// const int MOD = 1000000007;

// int main() {
//     int n;
//     cin >> n;
//     // 先计算奇数位个数i、偶数位个数j，那么奇数位和为[0,9i]，偶数位和为[0,9j]，两层循环求和，最终结果取模

//     long long totalSum = 0;
//     // int oddSize = 0, evenSize = 0;
//     // if(n%2 == 1) {
//     //     oddSize = n/2+1;
//     //     evenSize = n/2;
//     // } else {
//     //     oddSize = n/2;
//     //     evenSize = n/2;
//     // }
//     // cout << oddSize << evenSize << endl;
    
//     // for(int i = 1; i < 9*oddSize; i++) {
//     //     for(int j = 1; j < 9*evenSize; j++) {
//     //         totalSum += i*j;
//     //     }
//     // }
//     // totalSum = totalSum % MOD;

//     for (int i = 0; i < n/2; ++i) {
//         for (int digit = 0; digit <= 9; ++digit) {
//             long long oddSum = 0, evenSum = 0;
//             if (i % 2 == 0) {
//                 oddSum = digit;
//             } else {
//                 evenSum = digit;
//             }

//             for (int j = 1; j < n; ++j) {
//                 if (j % 2 == 1) {
//                     oddSum = (oddSum * 10 + digit) % MOD;
//                 } else {
//                     evenSum = (evenSum * 10 + digit) % MOD;
//                 }
//             }

//             long long sum = (oddSum * evenSum) % MOD;
//             totalSum = (totalSum + sum) % MOD;
//         }
//     }

//     cout << totalSum << endl;

//     return 0;
// }


#include<iostream>
using namespace std;
const int MOD = 1000000007;
long cal_10(int k) {
    if(k == 0) return 1;
    if(k == 1) return 10;
    if(k % 2 == 1) return ((cal_10(k/2) * cal_10(k/2) % MOD * 10) % MOD);
    else return (cal_10(k/2) * cal_10(k/2)) % MOD;
}

int main() {
    int n;
    cin >> n;
    int ji = (n+1) / 2;
    int ou = n / 2;
    int ji_sum = (ji * 45 * cal_10(ji-1)) % MOD;
    int ou_sum = (ou * 45 * cal_10(ou-1)) % MOD;
    cout << (ji_sum * ou_sum) % MOD;
    return 0;
}