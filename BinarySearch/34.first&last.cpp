#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return vector<int>(-1, -1);
        int lower = lower_bound(nums, target);
        int upper = upper_bound(nums, target) - 1;
        if(lower == nums.size() || nums[lower] != target){
            return vector<int>(-1, -1);
        }
        return vector<int>(lower, upper);
    }

    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid;
        while(l < r) {
            mid = (l + r) / 2;
            if(nums[mid] >= target)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    int upper_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid;
        while(l < r) {
            mid = (l + r) / 2;
            if(nums[mid] > target)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

int main(void) {
    Solution* sol = new Solution();
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);
    int target = 8;
    vector<int> res;
    res.assign((sol->searchRange(nums, target)).begin(), (sol->searchRange(nums, target)).end()); // vector<int>直接赋值存在问题？
    cout << "lower: " << sol->lower_bound(nums, target) << endl;
    cout << "higher: " << sol->upper_bound(nums, target) - 1 << endl;
    vector<int>::iterator it;
    for(it = (sol->searchRange(nums, target)).begin(); it != (sol->searchRange(nums, target)).end(); it++)
        cout << *it;
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++) {
        cout << res[i];
    }
    return 0;
}