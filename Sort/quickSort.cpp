#include<iostream>
#include<vector>
// #include"tools.h"
using namespace std;

// 快速排序，缩边式写法
void quick_sort(vector<int>& nums, int l, int r) {
    if(l < r) {
        // int mid = rand() % (r - l + 1) + l;
        // swap(nums[mid], nums[r]);
        int mid = (l+r)/2;
        int currVal = nums[r];
        int i = l, j = r;
        for(j = l; j < r; j++) {
            if(nums[j] < currVal) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        // nums[r] = nums[i];
        // nums[i] = currVal;
        swap(nums[i], nums[r]);
        quick_sort(nums, l, i-1);
        quick_sort(nums, i+1, r);
    }
}

// 快速排序，填坑式写法
void quickSort(vector<int>& nums, int l, int r) {
    if(l < r) {
        // int mid = (l+r)/2;
        // int currVal = nums[mid];
        int mid = rand() % (r - l + 1) + l;
        int currVal = nums[mid];
        swap(nums[mid], nums[r]);
        int i = l, j = r;
        while(i < j) {
            while(i < j && nums[i] <= currVal) i++;
            if(i < j) nums[j--] = nums[i];
            while(i < j && nums[j] >= currVal) j--;
            if(i < j) nums[i++] = nums[j];
        }
        nums[i] = currVal;

        // // 中轴压缩
        // while(i > 0 && nums[i] == nums[i-1]) i--;
        // while(j < nums.size()-1 && nums[j] == nums[j+1]) j++;
        // quickSort(nums, j+1, r);
        
        quickSort(nums, l, i-1);
        quickSort(nums, i+1, r);
    }
}

// 非递归地快速排序
void quickSort_noRecursion(vector<int>& nums, int l, int r) {
    
}

int main() {
    int n;
    vector<int> nums;
    srand((unsigned)time(NULL)); // 生成与时间绑定的随机因子
    while(cin >> n) {
        if(getchar() == '\n') {
            nums.push_back(n);
            quickSort(nums, 0, nums.size()-1);
            // quick_sort(nums, 0, nums.size()-1);
            for(int i = 0; i < nums.size(); i++)
                cout << nums[i] << " ";
            nums.clear();
        } else {
            nums.push_back(n);
        }
    }
    return 0;
}