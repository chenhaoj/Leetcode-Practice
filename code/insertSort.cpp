// #include<iostream>
#include<vector>
// #include"tools.h"

void insert_sort(std::vector<int> &nums) {
    for(int i = 0; i < nums.size(); ++i) {
        for(int j = i; j > 0 && nums[j] < nums[j-1]; --j) {
            swap(nums[j], nums[j-1]);
        }
    }
}