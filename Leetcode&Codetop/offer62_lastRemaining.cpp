/* 
剑指offer62. 圆圈中最后剩下的数字
约瑟夫环问题
 */

#include<iostream>
#include<queue>
#include<list>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    queue<int> q;
    for(int i = 0; i < n; i++) {
        q.push(i);
    }
    int count = 1;
    int last = 0;
    while(!q.empty()) {
        last = q.front();
        q.pop();
        if(count % m != 0) q.push(last);
        count++;
    }
    cout << last << endl;
    return 0;
}