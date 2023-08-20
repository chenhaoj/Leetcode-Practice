#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int binarySort(vector<int>& nums) {
    int l = 0, r = nums.size()-1;
    while(l <= r) {
        int mid = (l+r)/2;
        cout << "l=" << l << " r=" << r << " mid=" << mid << endl;
        if(mid == nums.size()-1 || mid == 0) return nums[mid];
        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
            return nums[mid];
        }
        else if(nums[mid] == nums[mid-1]) {
            l = mid + 1;
        }
        else if(nums[mid] == nums[mid+1]) {
            r = mid - 1;
        }
    }
    return r;
}

int main() {
    vector<int> nums;
    nums.push_back(0);
    for(int i = 1; i < 5; i++) {
        nums.push_back(i);
        nums.push_back(i);
    }
    // nums.push_back(5);
    // for(int i = 6; i < 9; i++) {
    //     nums.push_back(i);
    //     nums.push_back(i);
    // }
    cout << binarySort(nums);

    return 0;
}