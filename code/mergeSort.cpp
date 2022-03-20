// #include<iostream>
#include<vector>

void merge(std::vector<int> &nums, int l, int r) {
    int mid = (l+r)/2;
    if(l == mid) 
        return;
    if(l < mid && mid < r) {
        merge(nums, l, mid);
        merge(nums, mid, r);
    }
    std::vector<int> temp;
    
    // 两段比较，在新数组中排序
    int i = l, j = mid;
    while(i < mid && j < r) {
        if(nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
        }
    }
    if(i == mid) {
        while(j < r) {
            temp.push_back(nums[j]);
            j++;
        }
    } else {
        while(i < mid) {
            temp.push_back(nums[i]);
            i++;
        }
    }

    // for(int i = 0; i < temp.size(); i++) {
    //     std::cout << temp[i] << " ";
    // }
    // std::cout << std::endl;

    for(int index = 0; index < r - l; ++index) {
        nums[l+index] = temp[index];
    }
}