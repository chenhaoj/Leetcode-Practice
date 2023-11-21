#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> T;
    while(n--) {
        int t;
        cin >> t;
        T.push_back(t);
    }
    int a, b = 0;
    int sum = 0;
    int i = 0;
    while(i < T.size() || a != 0 || b != 0) {
        if(a == 0) {
            if(i < T.size()) a += T[i++];
            else if(b != 0) {
                sum += b;
                b = 0;
            }
        } else if (b == 0) {
            if(i < T.size()) b += T[i++];
            else if(a != 0) {
                sum += a;
                a = 0;
            }
        }

        if(a < b) {
            sum += a;
            b -= a;
            a = 0;
        } else {
            sum += b;
            a -= b;
            b = 0;
        }
        cout << "a = " << a << ", b = " << b << endl;
    }
    cout << sum << endl;
    return 0;
}