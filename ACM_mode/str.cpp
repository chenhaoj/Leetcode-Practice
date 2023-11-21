#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string s;
    vector<string> vec;
    while(getline(cin, s)) {
        cout << s << endl;
        string tmp;
        for(char c: s) {
            if(c == ' ') {
                vec.emplace_back(tmp);
                tmp.clear();
            } else {
                tmp += c;
            }
        }
        vec.push_back(tmp);
        // vec.push_back(s);
        // if(getchar() == '\n') {
        //     sort(vec.begin(), vec.end());
        //     for(auto v: vec) {
        //         cout << v << " ";
        //     }
        //     cout << endl;
        //     vec.clear();
        // }
    }
    return 0;
}