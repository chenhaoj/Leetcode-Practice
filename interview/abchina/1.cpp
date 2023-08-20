#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    string str1 = "121";
    string str2 = "1212";
    int i = str1.size()-1;
    int j = str2.size()-1;
    int flag = 0;
    string res = "";
    while(i >= 0 || j >= 0) {
        int x = i >= 0 ? str1[i]-'0': 0;
        int y = j >= 0 ? str2[j]-'0': 0;
        int z = x + y + flag;
        int cur = z % 3;
        flag = z/3;
        res += cur+'0';
        i--;j--;
    }
    if(flag) res += '1';
    reverse(res.begin(), res.end());
    // string res2 = "";
    // for(int t = res.size()-1; t >= 0; t--) {
    //     res2 += res[t];
    // }
    cout << res << endl;
    return 0;
}