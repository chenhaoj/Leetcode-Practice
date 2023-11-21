#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * return topK string
     * @param strings string字符串vector strings
     * @param k int整型 the k
     * @return string字符串vector<vector<>>
     */
    vector<vector<string> > topKstrings(vector<string>& strings, int k) {
        //先用int计数 然后再用to_string把它转换成字符串
        map<string, int> mp;
        vector<vector<string> > res;
        
        for(const auto &i : strings){
            mp[i]++;
        }
        for(auto it = mp.begin(); it != mp.end(); it++) {
            res.push_back({it->first,to_string(it->second)});
        }
        /*sort(words.begin(),words.end(),
            [](const string &a, const string &b){
                return a.size() < b.size();
        });*/

        sort(res.begin(), res.end(), [](vector<string> &m, vector<string> &n){
            //如果是mp[0]=1;mp[1]=1
            if(m[1] == n[1]){
                return m[0] < n[0];
            } else { //mp[1] = '2' mp[2] = '1' 得把'2'变成 2
                return stoi(m[1]) > stoi(n[1]);
            }    
        });
        
        //重新赋大小 不重新赋大小 会多出["3","1"]
        res.resize(k);
        return res;
    }
};

int main() {
    Solution* sol = new Solution();
    return 0;
}