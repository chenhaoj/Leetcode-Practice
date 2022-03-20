// #include<iostream>
#include<vector>

// 堆排序，以生成大根堆/小根堆
// nums:待排序的数组.   i:排序的起点.   n:排序的终点.
void adjustHeap(std::vector<int> &nums, int i, int n) {
    int parent = i; // 当前树的根
    int child = 2 * i + 1; // 左孩子
    while(child < n) {
        if(child + 1 < n && nums[child] < nums[child+1]) {
            child++;
        }
        if(nums[parent] < nums[child]) {
            swap(nums[parent], nums[child]);
            parent = child;
        }
        child = 2 * child + 1;
    }
}

// 初始化堆
void buildHeap(std::vector<int> &nums) {
    for(int i = nums.size()/2-1; i >= 0; --i) {
        adjustHeap(nums, i, nums.size());
    }
}

// 交换堆的根节点和尾节点，并从堆的尾节点取数，重新调整堆
void heap_sort(std::vector<int> &nums) {
    buildHeap(nums);
    for(int i = nums.size()-1; i >= 0; --i) {
        swap(nums[0], nums[i]);
        adjustHeap(nums, 0, i); // WARN：这里非常关键！因为本身已经是大/小跟堆，因此可以借助adjustHeap中child的变化实现堆的排序；
                                //      初始化的时候不行，因为初始化时完全乱序，如果从根节点开始，那么上层的走下来之后就无法回溯。      
    }
}