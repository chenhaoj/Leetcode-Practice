#include <iostream>
#include <vector>
using namespace std;

vector<int> father;
vector<int> height;

int find(int x) {
    return father[x] == x ? x : father[x] = find(father[x]);
}

void merge(int x, int y) {
    int fa = find(x);
    int fb = find(y);
    if(fa == fb) return;

    if(height[fa] < height[fb]) {
        father[fa] = fb;
    } else {
        father[fb] = fa;
        if(height[fa] == height[fb])
            height[fa]++;
    }
}

int main() {

}