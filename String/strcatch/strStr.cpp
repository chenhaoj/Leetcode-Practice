#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
// -------------------最笨：暴力匹配-------------------
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        for(int i = 0; i + m <= n; i++) {
            bool flag = true;
            for(int j = 0; j < m; j++) {
                if(haystack[i + j] != needle[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) return i;
        }
        return -1;
    }
};

int main() {
    Solution *test = new Solution();
    int next[6];

    // test->getNext_2(next, "aabaaf");
    // for(int i = 0; i < 6; i++) {
    //     cout << next[i] << " ";
    // }
    // cout << endl;

    // TEST：haystack = "hello", needle = "ll" RESULT：2
    cout << test->strStr("hello", "ll") << endl;
    return 0;
}