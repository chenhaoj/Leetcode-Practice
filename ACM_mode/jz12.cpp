#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 
     * @return bool布尔型
     */
    vector<vector<int> > visited;
    bool dfs(vector<vector<char> >& matrix, int i, int j, string word, int k) {
        // cout << "???";
        cout << "i=" << i << "j=" << j << "m=" << matrix[i][j] << " find=" << word[k];
        if(k == word.length()) return true;
        visited[i][j] = 1;
        if(j+1 < matrix[i].size() && matrix[i][j+1] == word[k]) 
            if(visited[i][j+1] != 1 && dfs(matrix, i, j+1, word, k+1)) return true;
        if(i+1 < matrix.size() && matrix[i+1][j] == word[k])
            if(visited[i+1][j] != 1 && dfs(matrix, i+1, j, word, k+1)) return true;
        if(j-1 >= 0 && matrix[i][j-1] == word[k])
            if(visited[i][j-1] != 1 && dfs(matrix, i, j-1, word, k+1)) return true;
        if(i-1 >= 0 && matrix[i-1][j] == word[k])
            if(visited[i-1][j] != 1 && dfs(matrix, i-1, j, word, k+1)) return true;
        cout << "走完" << endl;
        return false;
    }
    
    bool hasPath(vector<vector<char> >& matrix, string word) {
        visited.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
        bool ans = false;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == word[0]) {
                    cout << "matrix[" << i << "][" << j << "]=" << matrix[i][j] << endl;
                    // cout << "进入" << endl;
                    ans = dfs(matrix, i, j, word, 1);
                    if(ans) return true;
                    visited.clear();
                }
            }
        }
        return ans;
    }
};

int main() {
    // vector<vector<char> > nums{{'a','b','c','e','h'},{'j','i','g','s','f'},{'c','s','l','o','p'},{'q','a','d','e','e'},{'m','n','o','e','a'},{'d','i','d','e','j'},{'f','m','v','c','e'},{'i','f','g','g','s'}};
    // Solution* sol = new Solution();
    // string str = "sggfiecvaasabceejigoem";
    // if(sol->hasPath(nums, str)) cout << 1 << endl;
    // else cout << 0 << endl;
    vector<int> f(50, 0);
    return 0;
}