#include<iostream>
using namespace std;

int Euclid(int m, int n) {
    int r = m % n;
    if(r == 0) return n;
    else {
        m = n;
        n = r;
        Euclid(m, n);
    }
}

int gcd(int m, int n) {
    // Euclid(m, n);
    if(n == 0) return m;
    else return Euclid(n, m%n);
}

int main() {
    int m = 30, n = 20;
    cout << gcd(m, n) << endl;
}