/* 题目描述
695. Max Area of Island(Easy)
    给定一个二维的 0-1 矩阵，其中 0 表示海洋，1 表示陆地。单独的或相邻的陆地可以形成岛
屿，每个格子只与其上下左右四个格子相邻。求最大的岛屿面积。
    输入是一个二维数组，输出是一个整数，表示最大的岛屿面积。
    Input:
        [[1,0,1,1,0,1,0,1],
        [1,0,1,1,0,1,1,1],
        [0,0,0,0,0,0,0,1]]
    Output: 
        6
 */

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
// #include<list>
int dfs_1(std::vector<std::vector<int> >& grid, int r, int c);
int dfs_2(std::vector<std::vector<int> >& grid, int r, int c);
int maxAreaOfIsland_By_Stack(std::vector<std::vector<int> >& grid);
int maxAreaOfIsland_By_Recursion(std::vector<std::vector<int> >& grid);

// DFS栈实现
std::vector<int> directions{-1, 0, 1, 0, -1};
int maxAreaOfIsland_By_Stack(std::vector<std::vector<int> >& grid) {
    int m = grid.size(), n = m ? grid[0].size(): 0, local_area, area = 0, x, y;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j]) {
                local_area = 1;
                grid[i][j] = 0;
                std::stack<std::pair<int, int> > island;
                island.push({i, j});
                while(!island.empty()) {
                    auto [r, c] = island.top();
                    island.pop();
                    for(int k = 0; k < 4; k++) {
                        x = r + directions[k];
                        y = c + directions[k+1];
                        if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                            grid[x][y] = 0;
                            local_area++;
                            island.push({x, y});
                        }
                    }
                }
                area = std::max(area, local_area);
            }
        }
    }
    return area;
}

// DFS递归实现
int maxAreaOfIsland_By_Recursion(std::vector<std::vector<int> >& grid) {
    if(grid.empty() || grid[0].empty()) return 0;
    int max_area = 0;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            // 先判断边界有效，再递归
            // if(grid[i][j] == 1) {
            //     max_area = std::max(max_area, dfs_1(grid, i, j));
            // }

            // 先搜索，等下一次搜索开始时再判断是否合法
            max_area = std::max(max_area, dfs_2(grid, i, j));
        }
    }
    return max_area;
}

int dfs_1(std::vector<std::vector<int> >& grid, int r, int c) {
    if(grid[r][c] == 0) return 0;
    grid[r][c] = 0;
    int x, y, area = 1; // int x, y; int area = 1;
    for(int k = 0; k < 4; k++) {
        x = r + directions[k];
        y = c + directions[k+1];
        if(x >=0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
            area += dfs_1(grid, x, y);
        }
    }
    return area;
}

int dfs_2(std::vector<std::vector<int> >& grid, int r, int c) {
    if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) 
        return 0;
    grid[r][c] = 0;
    return 1 + dfs_2(grid, r-1, c) + dfs_2(grid, r, c+1) + dfs_2(grid, r+1, c) + dfs_2(grid, r, c-1);
}

int main() {
    // int array[3][8] = {1,0,1,1,0,1,0,1,
    //                   1,0,1,1,0,1,1,1,
    //                   0,0,0,0,0,0,0,1};
    std::vector<std::vector<int> > array;
    std::vector<int> row1{1,0,1,1,0,1,0,1};
    std::vector<int> row2{1,0,1,1,0,1,1,1};
    std::vector<int> row3{0,0,0,0,0,0,0,1};
    array.push_back(row1);
    array.push_back(row2);
    array.push_back(row3);

    // std::vector<int>::iterator it = array[0];
    // it = array.begin();
    // std::cout << *it << std::endl;
    // std::cout << array[1][0] << std::endl;
    // std::list<int> row1{1,0,1,1,0,1,0,1};
    // std::list<int> row2{1,0,1,1,0,1,1,1};
    // std::list<int> row3{0,0,0,0,0,0,0,1};
    // std::vector<int> array{row1, row2, row3};
    // std::vector<int> row{};
    std::cout << maxAreaOfIsland_By_Recursion(array) << std::endl;
    return 0;
}