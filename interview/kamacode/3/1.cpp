#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> fish(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> fish[i];
    }
    
    queue<int> q;
    int ans = 0;
    int flag = 1;
    while(flag) {
        int i = 0;
        q.push(fish[0]);
        while(i+1 < fish.size()) {
            if(fish[i] <= fish[i+1]) {
                q.push(fish[i+1]);
            }
            i++;
        }
        if(q.size() == fish.size()) {
            flag = 0;
            break;
        }
        
        // update fish
        fish.resize(q.size());
        i = 0;
        while(!q.empty()) {
            fish[i++] = q.front();
            q.pop();
        }
        ans++;
    }
    cout << ans;    
    return 0;
}