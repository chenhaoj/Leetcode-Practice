#include<iostream>
using namespace std;

// 直接打表更快
int main() {
    string str;
    cin >> str;
    string ans;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            ans += str[i];
        } else {
            ans += str[i];

            if(str[i] - 'u' > 0) ans += 'u';
            else if(str[i] - 'o' > 0) {
                if(abs(str[i]-'u') < abs(str[i]-'o')) ans += 'u';
                else ans += 'o';
            } else if(str[i] - 'i' > 0) {
                if(abs(str[i]-'o') < abs(str[i]-'i')) ans += 'o';
                else ans += 'i';
            } else if(str[i] - 'e' > 0) {
                if(abs(str[i]-'i') < abs(str[i]-'e')) ans += 'i';
                else ans += 'e';
            } else if(str[i] - 'a' > 0) {
                if(abs(str[i]-'e') < abs(str[i]-'a')) ans += 'e';
                else ans += 'a';
            }

            if(str[i] == 'z') ans += 'z';
            else if(str[i]+1 == 'e' || str[i]+1 == 'i' || str[i]+1 == 'o' || str[i]+1 == 'u') ans += str[i] + 2;
            else ans += str[i] + 1;
        }
    }
    cout << ans << endl;
    return 0;
}