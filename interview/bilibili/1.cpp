#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0;
    int i = 1;
    while(pow(10, i) <= n) {
        i++;
    }
    int mid = i/2;
    if(i % 2 == 1) {
        for(int j = 1; j <= mid; j++) {
            res = res * 10 + 9;
        }
    } else {
        for(int j = i; j > i/2; j--) {
            n /= 10;
        }
        res = n;
    }
    cout << res << endl;
    return 0;
}