#include <iostream>
#include <vector>
using namespace std;

int getMaxHighLoc(int a, int b) {
    int weishu_a=0, weishu_b = 0;
    int high_a=0, high_b = 0;

    int temp_a = a;
    while(temp_a/10 != 0) {
        weishu_a++;
        temp_a = temp_a / 10;
    }
    high_a = temp_a % 10; // 最高位

    int temp_b = b;
    while(temp_b/10 != 0) {
        weishu_b++;
        temp_b = temp_b / 10;
    }
    high_b = temp_b % 10; // 最高位

    if(high_a > high_b)
        return a;
    else if(high_a < high_b)
        return b;
    else
        return getMaxHighLoc(a-high_a*(10*weishu_a), b-high_b*(10*weishu_b));
    // for(int i = 0; i < nums.size(); i++) {
    //     int temp = nums[i];
    //     while(temp/10 != 0) (
    //         weishu++;
    //         temp = temp / 10;
    //     )
    //     high_num = temp % 10; // 最高位
    //     if(high_num > max_high)
    //         max_high = high_num;
    //     elseif(high_num == max_high)
    //         getMaxHighLoc()
};

int main() {
    cout << getMaxHighLoc(220, 234);
    return 0;
}