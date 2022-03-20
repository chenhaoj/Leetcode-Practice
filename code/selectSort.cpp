// #include<iostream>
#include<vector>

void select_sort(std::vector<int> &nums) {
    int min;
    for(int i = 0; i < nums.size(); ++i) {
        min = nums[i];
        int j = i;
        while(j < nums.size()){
            if(nums[j] < min)
                swap(nums[j], min);
            j++;
        }
        nums[i] = min;
    }
}