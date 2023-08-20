#include<iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    // long sum = 0;
    // for(int i = 1; i <= n; i++) {
    //     sum += k * i;
    // }
    // cout << sum;
    // 等差数列求和
    cout << n * (k + k * n) / 2 << endl;
    return 0;
}