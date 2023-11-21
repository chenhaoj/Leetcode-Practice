#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void printVector(vector<int> nums) {
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void quickSort(vector<int>& nums, int l, int r) {
    if(l >= r) return;
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
    quickSort(nums, l, i-1);
    quickSort(nums, i+1, r);
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

int main() {
    vector<int> nums{1,8,6,2,5,4,7,3};
    srand((unsigned)time(NULL));
    // quickSort(nums, 0, nums.size()-1);
    quickSort_noRecursion(nums);
    printVector(nums);
    return 0;
}