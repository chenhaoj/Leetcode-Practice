#include<iostream>
#include<cmath>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> ump;
    int num_size = 0;
    while(n--) {
        int a, b;
        cin >> a >> b;
        ump[a] = b;
        num_size += b;
    }
    double k = log2(num_size);
    cout << k << endl;
    return 0;
}