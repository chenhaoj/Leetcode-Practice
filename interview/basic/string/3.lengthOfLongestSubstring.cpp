#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    // 双指针
    int l, r = 0;
    int currLength = 0;
    int res = 0;
    while(r < s.size()) {
        for(int i = l; i < r; i++) {
            if(s[i] == s[r]) {
                l = i + 1;
                currLength = r - l;
            }
        }
        r++;
        currLength++;
        res = max(res, currLength);
    }
    return res;
}

int lengthOfLongestSubstring_set(string s) {
    // set实现
    int l = 0;
    int res = 0;
    unordered_set<char> us;
    for(int i = 0; i < s.length(); i++) {
        while(us.find(s[i]) != us.end()) {
            us.erase(s[l]);
            l++;
        }
        us.insert(s[i]);
        res = max(res, i - l + 1);
    }
    return res;
}

int main() {
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    cout << lengthOfLongestSubstring(s1);
    cout << lengthOfLongestSubstring(s2);
    cout << lengthOfLongestSubstring(s3);
    cout << lengthOfLongestSubstring_set(s1);
    cout << lengthOfLongestSubstring_set(s2);
    cout << lengthOfLongestSubstring_set(s3);
    return 0;
}