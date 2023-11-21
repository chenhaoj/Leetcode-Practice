// #include <iostream>
// #include <vector>
// using namespace std;

// const int MOD = 1000000007;

// long long subarrayWeightSum(int n, vector<int>& arr) {
//     long long totalSum = 0;
//     for (int i = 0; i < n; ++i) {
//         for (int j = i; j < n; ++j) {
//             vector<int> subarray(arr.begin() + i, arr.begin() + j + 1);
//             long long subarrayWeight = 0;
//             for (int k = 0; k < subarray.size(); ++k) {
//                 subarrayWeight += (k + 1) * subarray[k];
//             }
//             totalSum += subarrayWeight;
//         }
//     }
//     return totalSum % MOD;
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> arr[i];
//     }

//     long long result = subarrayWeightSum(n, arr);
//     cout << result << endl;

//     return 0;
// }

// #include <iostream>
// #include <math.h>
// using namespace std;
// const int MOD = 1000000007;
// int main() {
//     int n;
//     int* a = new int [n+1];
//     cin >>n;
//     for(int i=1;i<=n;++i) {
//         cin >> a[i];
//     }

//     long int sum =0;
//     for(int i=1; i<=n ;++i) {
//         //加上后面的所有数的个数*自身
//         sum += (n-i+1)*a[i]*1;
//         //加前面
//         for(int k=1; k<i; ++k){
//             sum+=((((n-k+1)-(i-k))*a[i]) % MOD *(i-k+1)) % MOD;
//         }
//     }
//     cout << sum << endl;
//     return 0;
// }

#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;
int main() {
    int n;
    cin >> n;
    dp.resize(n+1);
    vector<int> nums(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    dp[0] = 0;
    dp[1] = nums[1];
    for(int i = 2; i <= n; i++) {
        dp[i] = 2*dp[i-1] - dp[i-2] + (i*(i+1)/2)*nums[i];
    }
    cout << dp[n] << endl;
    return 0;
}