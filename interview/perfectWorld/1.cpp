#include<iostream>
#include<string>
using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    string str;
    int jin = 0;
    for(int i = str1.length()-1, j = str2.length()-1; i >= 0 || j >= 0 || jin > 0; i--, j--) {
        int first = i >= 0 ? str1[i] - '0': 0;
        int second = j >= 0? str2[j] - '0': 0;
        int sum = first+second+jin;
        jin = sum / 2;
        str += sum % 2 + '0';
    }
    reverse(str.begin(), str.end());
    cout << str << endl;
    return 0;
}

class Solution {
  public:
    /**
     * 字符串相加
     * @param str1 string字符串 第一个二进制数
     * @param str2 string字符串 第二个二进制数
     * @return string字符串
     */
    string solve(string str1, string str2) {
        string str;
        int jin = 0;
        for(int i = str1.length()-1, j = str2.length()-1; i >= 0 || j >= 0 || jin > 0; i--, j--) {
            int first = i >= 0 ? str1[i] - '0': 0;
            int second = j >= 0? str2[j] - '0': 0;
            int sum = first+second+jin;
            jin = sum / 2;
            str += sum % 2 + '0';
        }
        reverse(str.begin(), str.end());
        return str;
    }
};