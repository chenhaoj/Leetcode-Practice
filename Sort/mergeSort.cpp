#include<iostream>
#include<vector>
using namespace std;

// void merge(std::vector<int> &nums, int l, int r) {
//     int mid = (l+r)/2;
//     if(l == mid) 
//         return;
//     if(l < mid && mid < r) {
//         merge(nums, l, mid);
//         merge(nums, mid, r);
//     }
//     std::vector<int> temp;
    
//     // 两段比较，在新数组中排序
//     int i = l, j = mid;
//     while(i < mid && j < r) {
//         if(nums[i] <= nums[j]) {
//             temp.push_back(nums[i]);
//             i++;
//         } else {
//             temp.push_back(nums[j]);
//             j++;
//         }
//     }
//     if(i == mid) {
//         while(j < r) {
//             temp.push_back(nums[j]);
//             j++;
//         }
//     } else {
//         while(i < mid) {
//             temp.push_back(nums[i]);
//             i++;
//         }
//     }

//     // for(int i = 0; i < temp.size(); i++) {
//     //     std::cout << temp[i] << " ";
//     // }
//     // std::cout << std::endl;

//     for(int index = 0; index < r - l; ++index) {
//         nums[l+index] = temp[index];
//     }
// }

void mergeSort(vector<int>& nums, int l, int r) {
    // 递归版
    int mid = (l+r)/2;
    if(l == mid) return;
    if(l < mid && mid < r) {
        mergeSort(nums, l, mid);
        mergeSort(nums, mid, r);
    }

    vector<int> tmp;
    int i = l, j = mid;
    while(i < mid && j < r) {
        if(nums[i] <= nums[j]) {
            tmp.push_back(nums[i]);
            i++;
        } else {
            tmp.push_back(nums[j]);
            j++;
        }
    }
    if(i == mid) {
        while(j < r) {
            tmp.push_back(nums[j]);
            j++;
        }
    } else {
        while(i < mid) {
            tmp.push_back(nums[i]);
            i++;
        }
    }

    for(int k = 0; k < r - l; k++) {
        nums[l+k] = tmp[k];
    }
}

void merge_sort(vector<int>& nums, int len) {
    // 迭代地归并排序
    vector<int> tmp(len, 0);
    for(int step = 1; step < len; step += step) {
        for(int start = 0; start < len; start += 2*step) {
            int l = start, mid = min(start+step, len), r = min(start+2*step, len);
            int k = start;
            int start1 = l, end1 = mid, start2 = mid, end2 = r;
            while(start1 < end1 && start2 < end2) {
                tmp[k++] = nums[start1] < nums[start2] ? nums[start1++] : nums[start2++];
            }
            while(start1 < end1) {
                tmp[k++] = nums[start1++];
            }
            while(start2 < end2) {
                tmp[k++] = nums[start2++];
            }
            while(l < k) {
                nums[l] = tmp[l];
                l++;
            }
        }
    }
}

int main() {
    int n;
    vector<int> nums;
    while(cin >> n) {
        if(getchar() == '\n') {
            nums.push_back(n);
            mergeSort(nums, 0, nums.size());
            // merge_sort(nums, nums.size());
            for(int i = 0; i < nums.size(); i++)
                cout << nums[i] << " ";
            nums.clear();
        } else {
            nums.push_back(n);
        }
    }
    return 0;
}