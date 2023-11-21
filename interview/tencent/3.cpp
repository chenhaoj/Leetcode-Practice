#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nius(n);
    for(int i = 0; i < n; i++) {
        cin >> nius[i];
    }
    sort(nius.begin(), nius.end());
    int ans = 0;
    int l = 0, r = nius.size()-1;
    int zdl = 0;
    while(l <= r) {
        if(nius[r] - zdl > 0) {
            ans += nius[r] - zdl;
            zdl = nius[r];
        }
        r--;
        if(l < r && zdl - nius[l] >= 0) {
            zdl = nius[l];
        }
        l++;
    }
    cout << ans << endl;
    return 0;
}