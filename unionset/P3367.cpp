// https://www.luogu.com.cn/problem/P3367

#include <iostream>
#include <vector>
using namespace std;
vector<int> father;
vector<int> height;

int find(int i) {
    return father[i] == i ? i : father[i] = find(father[i]);
}

void merge(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    if(fa == fb) return;
    if(height[fa] < height[fb])
        father[fa] = fb;
    else {
        father[fb] = fa;
        if(height[fa] == height[fb]) height[fa]++;
    }
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    father.resize(n+1, 0);
    height.resize(n+1, 0);
    // init
    for(int i = 1; i <= n; i++) {
        father[i] = i;
        height[i] = 0;
    }
    int temp_m = m;
    int z, x, y;
    while(temp_m--) {
        cin >> z >> x >> y;
        if(z == 1) {
            merge(x, y);
        } else if(z == 2){
            if(find(x) == find(y)) cout << "Y" << endl;
            // 在后来合并的时候，并不会同步更新全部的father状态，必须经过find之后才会更新
            // if(father[x] == father[y]) cout << "Y" << endl; 
            else cout << "N" << endl;
        }
    }
    return 0;    
}