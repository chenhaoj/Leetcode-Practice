// #include<iostream>
#include<vector>

int binary_search(std::vector<int> &nums, int l, int r, int target) {
    int mid;
    while(l <= r) {
        mid = (l+r)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

void binary_insert_sort(std::vector<int> &nums) {
    int loc, temp;
    for(int i = 1; i < nums.size(); ++i) {
        // find correct location of nums[i]
        int l = 0, r = i - 1, mid = (l+r)/2, index;
        loc = binary_search(nums, l, r, nums[i]);
        // while(l <= r) {
        //     mid = (l+r)/2;
        //     if(nums[mid] == nums[i]){
        //         loc = mid;
        //         break;
        //     }
        //     else if(nums[mid] < nums[i])
        //         l = mid + 1;
        //     else
        //         r = mid - 1;
        //     loc = l;
        // }
        temp = nums[i];
        index = i;
        while(index > loc){
            nums[index] = nums[index-1];
            index--;
        }
        nums[loc] = temp;
    }
}