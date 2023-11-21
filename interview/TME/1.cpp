#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 暴力
int main() {
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            long long temp = nums[i] * nums[j];
            string s = to_string(temp);
            bool flag = true;
            for(int k = 1; k < s.length(); k++) {
                if(s[k] != '0') {
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}