#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        // 建立偏移表
        int hSize=haystack.size();
        int nSize=needle.size();
        unordered_map<char, int> pianyi;
        for(int i=0;i<nSize;i++) pianyi[needle[i]]=nSize-i;

        // 遍历
        int i=0;
        while(i<=hSize-nSize){
            if(haystack.substr(i,nSize)==needle) return i;
            else{
                // 查询substr后的字符的偏移值
                if(i+nSize>hSize-1) return -1;
                else{
                    if(pianyi.find(haystack[i+nSize])!=pianyi.end()){
                        i+=pianyi[haystack[i+nSize]];
                    }
                    else{
                        i+=nSize+1;
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution *test = new Solution();
    // int next[6];

    // test->getNext_2(next, "aabaaf");
    // for(int i = 0; i < 6; i++) {
    //     cout << next[i] << " ";
    // }
    // cout << endl;

    // TEST：haystack = "hello", needle = "ll" RESULT：2
    cout << test->strStr("hello", "ll") << endl;
    return 0;
}