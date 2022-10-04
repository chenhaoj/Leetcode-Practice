#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
// -------------------改进：Sunday-------------------
    int Sunday(string haystack, string needle) {
        // 建立偏移表
        int n = haystack.size(), m = needle.size();
        unordered_map<char, int> shift;
        for(int i = 0; i < m; i++) shift[needle[i]] = m - i;

        // 目标字符串的子串：待匹配串遍历查询
        int idx = 0;
        while(idx <= (n-m)) {
            if(haystack.substr(idx, m) == needle) return idx;
            else {
                if(shift.find(haystack[idx+m]) != shift.end()) {
                    idx += shift[haystack[idx+m]];
                }
                else {
                    idx += m + 1;
                }
            }
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
    cout << test->Sunday("hello", "ll") << endl;
    return 0;
}