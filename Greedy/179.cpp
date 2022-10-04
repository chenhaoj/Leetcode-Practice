#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// int getMaxHighLoc(int a, int b);

// void largestNumber(vector<int>& nums) {
//     // int high_num = 0;
//     // int curr_max = 0;
//     int curr_num = 0;
//     // int finish = 0;
//     // string ans = "";
//     curr_num = getMaxHighLoc(0, nums[0]);
//     curr_num = getMaxHighLoc(curr_num, nums[1]);
//     // for(int i = 1; i < nums.size(); i++) {
//     //     curr_num = getMaxHighLoc(curr_num, nums[i]);
//     // }
//     cout << curr_num;
//     // while(finish != nums.size()) {
//     //     for(int i = 0; i < nums.size(); i++) {
//     //         // 找到最高位
//     //         while(nums[i]/10 != 0) {
//     //             high_num = nums[i] / 10;
//     //         }
//     //         high_num = high_num / 10;
//     //         if(high_num > curr_max) {
//     //             curr_max = high_num;
//     //             curr_num = i;
//     //         }
//     //         else if(high_num == curr_max) {

//     //         }
//     //         curr_max = high_num;
//     //         cout << nums[i] << "最高位=" << high_num << endl;
//     //     }
//     //     finish++;
//     // }
//     // return "";
// }


// int getMaxHighLoc(int a, int b) {
//     int weishu_a=0, weishu_b = 0;
//     int high_a=0, high_b = 0;

//     int temp_a = a;
//     while(temp_a/10 != 0) {
//         weishu_a++;
//         temp_a = temp_a / 10;
//     }
//     high_a = temp_a % 10; // 最高位

//     int temp_b = b;
//     while(temp_b/10 != 0) {
//         weishu_b++;
//         temp_b = temp_b / 10;
//     }
//     high_b = temp_b % 10; // 最高位

//     if(high_a > high_b)
//         return a;
//     else if(high_a < high_b)
//         return b;
//     else {
//         int ll = getMaxHighLoc(a-high_a*(pow(10,weishu_a)), b-high_b*(pow(10,weishu_b)));
//         if(ll == a-high_a*(pow(10,weishu_a)))
//             return a;
//         else
//             return b;
//     }
//     // for(int i = 0; i < nums.size(); i++) {
//     //     int temp = nums[i];
//     //     while(temp/10 != 0) (
//     //         weishu++;
//     //         temp = temp / 10;
//     //     )
//     //     high_num = temp % 10; // 最高位
//     //     if(high_num > max_high)
//     //         max_high = high_num;
//     //     elseif(high_num == max_high)
//     //         getMaxHighLoc()
// };

// int main() {
//     vector<int> nums;
//     nums.push_back(3);
//     nums.push_back(30);
//     nums.push_back(34);
//     nums.push_back(5);
//     nums.push_back(9);
//     // largestNumber(nums);
//     cout << getMaxHighLoc(3, 30);
//     // cout << pow(10, 2);
//     return 0;
// }

bool str_cmp(string& a, string& b) {
    // cout << a+b << endl;
    // cout << b+a << endl;
    return a+b > b+a;
}

string largestNumber(vector<int>& nums) {
    vector<string> str;
    for(auto x : nums) {
        str.push_back(to_string(x));
    }
    // sort(str.begin(), str.end(), [](const string& a, const string& b){
    //     return a+b > b+a;
    // });
    sort(str.begin(), str.end(), [](string& a, string& b){
        return str_cmp(a, b);
    });
    string ans;
    int start = 1;
    for(auto x:str) {
        if(start) {
            if(x == "0") {
                continue;
            }
            else {
                start = 0;
            }
        }
        ans += x;
    }
    return ans.size()? ans : "0";
}

int main() {
    string a = "3";
    string b = "30";
    vector<int> nums;
    // nums.push_back(3);
    nums.push_back(0);
    nums.push_back(0);
    cout << largestNumber(nums);
    return 0;
}