#include <iostream>
using namespace std;

int global = 999;

/* dp三大步骤：
    1. 定义数组元素的含义：dp[i]表示什么；
    2. 找出数组元组之间的关系式：dp[n]和dp[n-1]、dp[n-2]之间有什么关系；
    3. 找出初始值，并对其初始化。
 */

/* 以青蛙跳台阶举例：
    1. dp[i]表示到第i级台阶需要的跳数；
    2. dp[n]=dp[n-1]+dp[n-2]：青蛙一次可以跳1级/2级台阶；
    3. dp[0]=0;dp[1]=1;dp[2]=2。
 */
int numWays(int n) {
    if(n <= 1) 
        return n;
    int dp[n]; // 静态数组写法
    // int *dp = new int[n+1]; // 动态数组写法
    // static int *dp = new int[n+1]; // 动态数组指针是静态的，直到程序结束才会从内存中删除。
    // int dp[] = new int[n+1]; // 错误写法
    dp[0] = 0; dp[1] = 1; dp[2] = 2;
    global = 998;
    
    for(int i = 3; i < n+1; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    static int h = 1122;
    cout << numWays(4) << endl;
    cout << h << endl;
    return 0;
}