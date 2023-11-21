#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    string str;
    cin >> str;
    vector<int> leftMulti, rightMulti;
    int left = 1, right = 1;
    for(int i = 0; i < str.length(); i++) {
        left *= str[i] - '0';
        leftMulti.push_back(left);
    }
    rightMulti.resize(str.length(), 0);
    for(int j = str.length()-1; j >= 0; j--) {
        right *= str[j] - '0';
        rightMulti[j] = right;
    }
    for(int i = 0; i < str.length(); i++) {
        cout << leftMulti[i] << " " << rightMulti[i] << endl;
    }
    int index = 0;
    while(index < str.length()-1 && leftMulti[index] != rightMulti[index+1]) {
        if(leftMulti[index] == rightMulti[index]) {
            break;
        }
        index++;
    }
    if(index == str.length()-1) cout << -1 << endl;
    else cout << index << endl;    
    return 0;
}