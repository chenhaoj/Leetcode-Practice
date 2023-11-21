#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<list>
using namespace std;

void printState(int n, vector<int> indegree, map<int, vector<int> > depend) {
    // 检查输入存储
    for(int i = 0; i < n; i++) {
        cout << "indegree=" << indegree[i];
        vector<int> temp = depend[i];
        cout << " && depend=";
        for(int j = 0; j < temp.size(); j++) {
            cout << temp[j] << ",";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> mem(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> mem[i];
    }
    // vector<int> finish(n, 0);
    vector<int> unfinish(n, 1);
    map<int, vector<int> > depend;
    vector<int> indegree(n, 0);
    queue<int> q;
    for(int i = 0; i < n; i++) {
        vector<int> yilai;
        for(int j = 0; j < n; j++) {
            int temp = 0;
            cin >> temp;
            if(temp == 1) {
                yilai.push_back(j);
            }
        }
        depend[i] = yilai;
        indegree[i] = yilai.size();
        if(yilai.size() == 0) {
            q.push(i);
            unfinish[i] = 0;
        }
    }
    // printState(n, indegree, depend);
    int result = 0;
    while(!q.empty()) {
        int size = q.size();
        // cout << size << endl;
        int idx = 0;
        int mem_need = 0;
        while(idx < size) {
            int cur = q.front();
            q.pop();
            // cout << "处理第" << cur << "任务      " << endl;
            mem_need += mem[cur];
            result = max(result, mem_need);
            for(int i = 0; i < n; i++) {
                vector<int> yilai = depend[i];
                for(int j = 0; j < yilai.size(); j++) {
                    if(yilai[j] == cur) {
                        yilai.erase(yilai.begin()+j);
                        depend[i] = yilai;
                        if(indegree[i] > 0) indegree[i]--;
                        break;
                    }
                }
                // printState(n, indegree, depend);
                if(indegree[i] == 0 && unfinish[i] == 1) {
                    q.push(i);
                    unfinish[i] = 0;
                }
            }
            idx++;
            // cout << endl;
        }
    }
    cout << result << endl;
    return 0;
}