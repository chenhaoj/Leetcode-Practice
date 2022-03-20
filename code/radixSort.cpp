// #include<iostream>
#include<vector>
#include<math.h>

int max_len(std::vector<int> nums) {
    int max_num = 0;
    int index = 0;
    while(index != nums.size()) {
        if(nums[index] > max_num)
            max_num = nums[index];
        index++;
    }
    int max_len = 0;
    while(max_num >= pow(10, max_len))
        max_len++;
    return max_len;
}

void radix_sort(std::vector<int> &nums) {
    int len = max_len(nums);
    std::vector<std::vector<int> > buckets(10);
    int round = 0;
    // for(int round = 0; round <= len; round++) {
    while(round < len) {
        int divisor = pow(10, round);
        // for(auto & theNum : nums) {
        //     int radix = (theNum/divisor) % 10;
        //     buckets[radix].push_back(theNum);
        // }
        for(int i = 0; i < nums.size(); i++) {
            int radix = (nums[i]/divisor) % 10;
            buckets[radix].push_back(nums[i]);
        }
        // buckets.clear();
        int index = 0;
        // for(auto & theBucket : buckets) {
        //     for(int & k : theBucket)
        //         nums[index++] = k;
        //     theBucket.clear();
        // }
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < buckets[i].size(); j++) {
                nums[index++] = buckets[i][j];
            }
            buckets[i].clear();
        }
        round++;
    }
}

// int main(void) {
//     std::vector<int> array = {1, 999, 10, 3, 2};
//     radix_sort(array);
//     for(auto & theNum : array) {
//         std::cout << theNum << std::endl;
//     }
//     return 0;
// }