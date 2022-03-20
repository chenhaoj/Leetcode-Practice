// #include<iostream>
#include<vector>

// 希尔排序：增序步长每次减少一半，即为nums.size()/2
void shell_sort(std::vector<int> &nums) {
    int dk = nums.size();
    while(dk > 0) {
        dk /= 2;
        for(int i = 0; i < dk; ++i) {
            int in_index = 1;
            while(i+in_index*dk < nums.size())
                in_index++; // 找到该组有多少数
            for(int in_i = i; in_i < in_index; ++in_i) {
                for(int j = in_i; j > 0 && nums[j] < nums[j-1]; --j) {
                    swap(nums[j], nums[j-1]);
                }
            }
        }
    }
}