#include<iostream>
#include<vector>

class Solution {
public:
    bool search(std::vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(nums[mid] == target)
                return true;
            if(nums[mid] == nums[start])
                start++;
            else if(nums[mid] <= nums[end]) {// 右边是连续的
                if(target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else { // 左边是连续的
                if(target >= nums[start] && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
        }
        return false;
    }
};