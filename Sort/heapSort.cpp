#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void adjustHeap(vector<int>& nums, int start, int end) {
    int parent = start;
    int child = 2*start+1;
    while(child < end) {
        if(child+1 < end && nums[child] > nums[child+1]) {
            child++;
        }
        if(nums[child] < nums[parent]) {
            swap(nums[child], nums[parent]);
            parent = child;
        }
        child = 2*child + 1;
    }
}

void buildHeap(vector<int>& nums) {
    for(int i = nums.size()/2-1; i >= 0; i--) {
        adjustHeap(nums, i, nums.size());
    }
}

void heapSort(vector<int>& nums) {
    buildHeap(nums);
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    for(int i = nums.size()-1; i > 0; i--) {
        swap(nums[0], nums[i]);
        adjustHeap(nums, 0, i);
    }
}

int main() {
    int n;
    vector<int> nums;
    while(cin >> n) {
        if(getchar() == '\n') {
            nums.push_back(n);
            heapSort(nums);
            for(int i = 0; i < nums.size(); i++)
                cout << nums[i] << " ";
            nums.clear();
        } else {
            nums.push_back(n);
        }
    }
    return 0;
}