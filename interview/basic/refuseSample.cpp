#include<iostream>
using namespace std;

/* rand5()生成rand7() */
int main() {
    // 为了用[1,5]生成[1,7]，得想办法生成6和7
    // rand() + rand() * n
    int a, b, val;
    while(true) {
        a = rand5(); // 生成[1,5]
        b = rand5()-1; // 生成[0,4]
        val = a + b * 5; // 组合成[1, 25]
        if(val > 21) {
            return 1 + (val-1) % 7;
        }
    }
}