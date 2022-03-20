// #include<iostream>
#include<vector>
// #include"tools.h"

// 快速排序
// 采用左闭右闭的写法
void quick_sort(std::vector<int> &nums, int l, int r) {
    if(l + 1 >= r) 
        return;
    int first = l, last = r, key = nums[first];
    while(first < last) {
        while(first < last && key <= nums[last])
            --last;
        nums[first] = nums[last];
        while(first < last && key >= nums[first])
            ++first;
        nums[last] = nums[first];
    }
    nums[first] = key;
    quick_sort(nums, l, first - 1);
    quick_sort(nums, first + 1, r);
}
