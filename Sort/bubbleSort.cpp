// #include<iostream>
#include<vector>
// #include"tools.h"

void bubble_sort(std::vector<int> &nums) {
    // 外循环控制排序轮数
    for(int i = 0; i < nums.size(); ++i) {
        // 内循环控制每轮比较次数
        for(int j = 1; j < nums.size() - i; ++j) {
            if(nums[j-1] > nums[j])
                std::swap(nums[j], nums[j-1]);
        }
    }
}