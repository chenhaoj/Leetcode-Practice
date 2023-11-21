#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100;
const int n = 10;
int f[maxn];
int height[maxn];

// 初始化
void init() {
    for(int i = 1; i <= n; i++) {
        f[i] = i;
        height[i] = 0;
    }
}

// 查询树
int find(int i) {
    // 非递归
    while(i != f[i])
        i = f[i];
    return i;
    // 递归
    if(i == f[i])
        return i;
    else
        return find(f[i]);
    // 简化
    return f[i] == i ? f[i] : find(f[i]);
    // 查询优化，每次遍历直接把节点都指向根
    return f[i] == i ? f[i] : f[i] = find(f[i]);
};

// 合并树
int merge(int a, int b) { // 把a合并到b
    // int fa = find(a);
    // int fb = find(b);
    // if(fa == fb) return;
    // else f[fa] = fb;
    // // 简化版
    // f[find(a)] = find(b);
    // 合并优化，避免树退化
    int fa = find(a);
    int fb = find(b);
    if(fa == fb) return;
    
    if(height[fa] < height[fb])
        f[fa] = fb;
    else {
        f[fb] = fa;
        if(height[fa] == height[fb]) height[fa]++;
    }
}

int main() {

}