#include <iostream>
using namespace std;

#define MAXN 10
int path[MAXN];
bool book[MAXN];
int n;

void dfs(int u) {
    if(u == n) {
        for(int i = 0; i < n; i++) {
            cout << path[i]+1 << " ";
        }
        cout << endl;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!book[i]) {
            book[i] = true;
            path[u] = i;
            dfs(u+1);
            book[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    return 0;
}