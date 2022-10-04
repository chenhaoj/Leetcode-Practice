#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 0;
        int ans = 0;
        while(end < nums.size()-1) {
            int maxPos = 0;
            for(int i=start; i<=end; i++) {
                maxPos = max(maxPos, i+nums[i]);
            }
            start = end+1;
            end = maxPos;
            ans++;
        }
        // int start=0, end=0, ans=0;
        // for(int i=0; i<nums.size()-1; i++) {
        //     int maxPos = max(maxPos, i+nums[i]);
        //     if(i==end) {
        //         end = maxPos;
        //         ans++;
        //     }
        // }
        return ans;
    }
};

int main() {
    Solution *sol = new Solution();
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    cout << sol->jump(nums);
    return 0;
}