#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

int minBlackCells(vector<vector<int> >& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int> > dist(n, vector<int>(m, -1));
    queue<Point> q;
    
    q.push(Point(0, 0));
    dist[0][0] = grid[0][0];
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = curr.x + dx[dir];
            int ny = curr.y + dy[dir];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int new_dist = dist[curr.x][curr.y] + grid[nx][ny];

                if (dist[nx][ny] == -1 || new_dist < dist[nx][ny]) {
                    dist[nx][ny] = new_dist;
                    q.push(Point(nx, ny));
                }
            }
        }
    }
    return dist[n - 1][m - 1];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int result = minBlackCells(grid);
    cout << result << endl;
    return 0;
}
