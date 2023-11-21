#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int> > matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int> > ans(n, vector<int>(n, -1));
    ans[0][0] = matrix[0][0];

    // for (int i = 1; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         int horse = -1;

    //         // + 越界判断
    //         if (j-2 >= 0 && i-1 >= 0) horse = ans[j - 2][i - 1];
    //         if (j-2 >= 0 && i+1 < n) horse = max(horse, ans[j - 2][i + 1]);
    //         if (j-1 >= 0 && i-2 >= 0) horse = max(horse, ans[j - 1][i - 2]);
    //         if (j-1 >= 0 && i+2 < n) horse = max(horse, ans[j - 1][i + 2]);
            
    //         ans[j][i] = horse == -1 ? -1 : horse + matrix[j][i];
    //         cout << ans[j][i] << " ";
    //     }
    // }
    for(int j = 1; j < n; j++) {
        for(int i = 0; i < n; i++) {
            int horse = -1;
            if(i-2 >= 0 && j-1 >= 0) horse = max(horse, ans[i-2][j-1]);
            if(i-2 >= 0 && j+1 < n) horse = max(horse, ans[i-2][j+1]);
            if(i+2 < n && j-1 >= 0) horse = max(horse, ans[i-2][j-1]);
            if(i+2 < n && j+1 >= 0) horse = max(horse, ans[i-2][j+1]);
            if(i-1 >= 0 && j-2 >= 0) horse = max(horse, ans[i-1][j-2]);
            if(i-1 >= 0 && j+2 < n) horse = max(horse, ans[i-1][j+2]);
            ans[i][j] = horse == -1 ? -1 : horse + matrix[i][j];
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    int out = ans[0][n-1];
    for (int i = 1; i < n; i++)
        out = max(out, ans[i][n-1]);
    cout << out << endl;
    return 0;
}