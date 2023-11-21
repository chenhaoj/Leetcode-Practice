#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int x;
    int y;
    node(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > array(n, vector<int>(m, 0));
    queue<pair<node, int> > q;
    array[0][0] = 1;
    q.push(make_pair(node(0, 0), 1));
    int num = 2;
    while(!q.empty()) {
        node curr = q.front().first;
        q.pop();
        if(curr.y < m-1 && array[curr.x][curr.y+1] == 0) {
            array[curr.x][curr.y+1] = num++;
            q.push(make_pair(node(curr.x, curr.y+1), num));
        }
        if(curr.x < n-1) {
            array[curr.x+1][curr.y] = num++;
            q.push(make_pair(node(curr.x+1, curr.y), num));
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}