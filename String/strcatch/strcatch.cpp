#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
// -------------------最笨：暴力匹配-------------------
    // int strStr(string haystack, string needle) {
    //     int n = haystack.length(), m = needle.length();
    //     for(int i = 0; i + m <= n; i++) {
    //         bool flag = true;
    //         for(int j = 0; j < m; j++) {
    //             if(haystack[i + j] != needle[j]){
    //                 flag = false;
    //                 break;
    //             }
    //         }
    //         if(flag) return i;
    //     }
    //     return -1;
    // }

// -------------------改进：Knuth-Morris-Pratt(KMP)-------------------
    // // next数组起始位置为-1的情况
    // int KMP_1(string haystack, string needle) {
    //     if(needle.size() == 0) return 0;
    //     int j = -1;
    //     int next[needle.size()];
    //     getNext_1(next, needle);
    //     for(int i = 0; i < haystack.size(); i++) {
    //         while(j >= 0 && haystack[i] != needle[j+1]) {
    //             j = next[j];
    //         }
    //         if(haystack[i] == needle[j+1]) {
    //             j++;
    //         }
    //         if(j == needle.size() - 1) {
    //             return (i - needle.size() + 1);
    //         }
    //     }
    //     return -1;
    // }

    // // next数组起始位置为0的情况
    // int KMP_2(string haystack, string needle) {
    //     if(needle.size() == 0) return 0;
    //     int j = 0;
    //     int next[needle.size()];
    //     getNext_2(next, needle);
    //     for(int i = 0; i < haystack.size(); i++) {
    //         while(j > 0 && haystack[i] != needle[j]) {
    //             j = next[j - 1];
    //         }
    //         if(haystack[i] == needle[j]) {
    //             j++;
    //         }
    //         if(j == needle.size()) {
    //             return (i - needle.size() + 1);
    //         }
    //     }
    //     return -1;
    // }
    
    // /* Next数组的关键点:
    //     s[i] != s[j]时，前缀指针向前回溯到指针前一项的next值
    //  */

    // // 前缀表统一减一的实现
    // // TEST:"aabaaf" RESULT:"-1 0 -1 0 1 -1"
    // void getNext_1(int* next, const string& s) {
    //     // 初始化：前缀索引和next[0]
    //     int j = -1;
    //     next[0] = j;
    //     for(int i = 1; i < s.size(); i++) { // 注意这里是从1开始遍历
    //         // 前缀和后缀不相等,前缀向前回溯
    //         while(j >= 0 && s[i] != s[j+1]) {
    //             j = next[j];
    //         }
    //         // 前缀和后缀相等
    //         if(s[i] == s[j+1]) {
    //             j++;
    //         }
    //         next[i] = j; // 将前缀长度j给next[i]
    //     }
    // }

    // // 前缀表正常实现
    // // TEST:"aabaaf" RESULT:"010120"
    // void getNext_2(int* next, const string& s) { // 和“统一减一”相比，关键差别在向前回溯索引
    //     int j = 0; // 初始化前缀索引
    //     next[0] = j;
    //     for(int i = 1; i < s.size(); i++) { // 注意i从1开始
    //         while(j > 0 && s[i] != s[j]) { // 不相等时向前回溯
    //             j = next[j - 1];
    //         }
    //         if(s[i] == s[j]) { // 前缀和后缀相等
    //             j++;
    //         }
    //         next[i] = j;
    //     }
    // }

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

// -------------------改进：Boyer-Moore(BM)-------------------
    
// -------------------改进：哈希法Hash-------------------

// -------------------改进：Horspool-------------------

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