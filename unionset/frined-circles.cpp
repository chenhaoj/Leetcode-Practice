#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> f;
vector<int> h;

int find(int i) {
    return f[i] == i ? i : f[i] = find(f[i]);
}

void merge(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    if(fa == fb) return;

    if(h[fa] < h[fb]) f[fa] = fb;
    else {
        f[fb] = fa;
        if(h[fa] == h[fb]) h[fa]++;
    }
    return;
}

int main() {
    int N;
    cin >> N;
    f.resize(N+1, 0);
    h.resize(N+1, 0);
    for(int i = 1; i <= N; i++) {
        f[i] = i;
    }
    vector<vector<int>> relations(N+1, vector<int>(N+1, 0));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int temp = 0;
            cin >> temp;
            if(temp == 1) {
                merge(i, j);
                relations[i][j] = temp;
            }
        }
    }
    int ans = 0;
    set<int> result;
    for(int i = 1; i <= N; i++) {
        if(f[i] == i) ans++;
        if(result.find(i) == result.end()) {
            result.insert(find(i));
        }
    }
    // cout << ans << endl;
    cout << ans << " " << result.size() << endl;
    return 0;
}