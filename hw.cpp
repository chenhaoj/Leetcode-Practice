#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

void quickSort(vector<int>& nums, int l, int r) {
    if(l < r) {
        int mid = rand() % (r - l + 1) + l;
        int target = nums[mid];
        swap(nums[mid], nums[r]);
        int i = l, j = r;
        while(i < j) {
            while(i < j && nums[i] <= target) i++;
            if(i < j) nums[j--] = nums[i];
            while(i < j && nums[j] >= target) j--;
            if(i < j) nums[i++] = nums[j];
        }
        nums[i] = target;
        quickSort(nums, l, i-1);
        quickSort(nums, i+1, r);
    }
}

stack<pair<int, int> > st;
void quickSort_noRecursion(vector<int>& nums) {
    st.push(make_pair(0, nums.size()-1));
    while(!st.empty()) {
        int l = st.top().first;
        int r = st.top().second;
        st.pop();
        if(l < r) {
            int mid = rand() % (r-l+1) + l;
            int curr = nums[mid];
            swap(nums[mid], nums[r]);
            int i = l, j = r;
            while(i < j) {
                while(i < j && nums[i] <= curr) i++;
                if(i < j) nums[j--] = nums[i];
                while(i < j && nums[j] >= curr) j--;
                if(i < j) nums[i++] = nums[j];
            }
            nums[i] = curr;
            st.push(make_pair(l, i-1));
            st.push(make_pair(i+1, r));
        }
    }
}

// 归并递归写法
void mergeSort_recursion(vector<int>& nums, int l, int r) {
    int mid = (l+r)/2;
    if(l == mid) return;
    // 分治divide
    if(l < mid && mid < r) {
        mergeSort_recursion(nums, l, mid);
        mergeSort_recursion(nums, mid, r);
    }
    // 合并merge
    vector<int> temp;
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
    
    for(int k = 0; k < r-l; k++) {
        nums[l+k] = temp[k];
    }
}

// 归并迭代写法
void mergeSort_iterate(vector<int>& nums) {
    int len = nums.size();
    vector<int> temp(len, 0);
    for(int step = 1; step < len; step += step) { // 步长等比变化
        for(int start = 0; start < len; start += 2*step) {
            int l = start, mid = min(start+step, len), r = min(start+2*step, len);
            int k = start;
            int start1 = l, end1 = mid, start2 = mid, end2 = r;
            while(start1 < end1 && start2 < end2) {
                temp[k++] = nums[start1] < nums[start2] ? nums[start1++] : nums[start2++];
            }
            while(start1 < end1)
                temp[k++] = nums[start1++];
            while(start2 < end2)
                temp[k++] = nums[start2++];
            while(l < k) {
                nums[l] = temp[l];
                l++;
            }
        }
    }
}

// 堆排序
void adjustHeap(vector<int>& nums, int start, int end) {
    int parent = start;
    int child = 2*start+1;
    while(child < end) {
        // 找两子中较小的那个
        if(child+1 < end && nums[child] > nums[child+1]) {
            child++;
        }
        if(nums[child] < nums[parent]) {
            swap(nums[child], nums[parent]);
            parent = child;
        }
        child = 2* child + 1;
    }
}

void buildHeap(vector<int>& nums) {
    for(int i = nums.size()/2-1; i >= 0; i--) {
        adjustHeap(nums, i, nums.size());
    }
}

void heapSort(vector<int>& nums) {
    buildHeap(nums);
    for(int i = nums.size()-1; i >= 0; i--) {
        swap(nums[0], nums[i]);
        adjustHeap(nums, 0, i);
    }
}

int main() {
    // quickSort
    srand((unsigned)time(NULL));
    int n;
    vector<int> nums;
    while(cin >> n) {
        if(getchar() == '\n') {
            nums.push_back(n);
            // quickSort(nums, 0, nums.size()-1);
            // mergeSort_recursion(nums, 0, nums.size());
            mergeSort_iterate(nums);
            // heapSort(nums);
            for(int i = 0; i < nums.size(); i++) {
                cout << nums[i] <<  " ";
            }
            cout << endl;
            nums.clear();
        } else {
            nums.push_back(n);
        }
    }
    return 0;
}