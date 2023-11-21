#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxPathSum(vector<vector<int> >& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    // Initialize a dp array to store the maximum sum for each cell
    vector<vector<int> > dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    
    // Fill the first row and first column of dp array
    for (int i = 1; i < m; ++i)
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    
    for (int j = 1; j < n; ++j)
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    
    // Fill the rest of the dp array using the recurrence relation
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    
    // Return the maximum sum for the bottom-right cell
    return dp[m - 1][n - 1];
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;
    
    vector<vector<int> > grid(m, vector<int>(n));
    cout << "Enter the grid values:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    
    int result = maxPathSum(grid);
    cout << "The maximum sum of the path is: " << result << endl;
    
    return 0;
}