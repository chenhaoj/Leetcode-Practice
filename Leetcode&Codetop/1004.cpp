#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        for(int left = 0, right = 0, sum = 0; right < nums.size(); right++) {
            sum += nums[right] == 1 ? 0 : 1;
            while(sum > k) {
                sum -= nums[left] == 0 ? 1 : 0;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main() {
    Solution* sol = new Solution;
    vector<int> nums{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << sol->longestOnes(nums, 3) << endl;
    return 0;
}