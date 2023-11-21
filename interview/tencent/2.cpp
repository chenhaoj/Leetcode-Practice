#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<float> a(n);
        vector<float> b(n-1);
        // unordered_map<int,int> ump;
        // vector<bool> visited;
        for(int j = 0; j < n; j++) {
            cin >> a[j];
        }
        for(int j = 0; j < n-1; j++) {
            cin >> b[j];
        }
        // 计算中位数
        vector<float> temp(n);
        for(int i = 0; i < n; i++) {
            temp[i] = a[i];
        }
        sort(temp.begin(), temp.end());
        // for(int i = 0; i < temp.size(); i++) {
        //     cout << temp[i] << " ";
        // }
        // visited.resize(n);
        int del_index = 0;
        while(temp.size() >= 0) {
            if(temp.size() % 2 == 0) { // 偶数
                if(((int)temp[temp.size()/2-1] + (int)temp[temp.size()/2]) % 2 == 0) 
                    printf("%d ", ((int)temp[temp.size()/2-1] + (int)temp[temp.size()/2])/2);
                else {
                    float mid_num = (temp[temp.size()/2-1] + temp[temp.size()/2])/2;
                    printf("%.1f ", mid_num);
                }
            } else { 
                printf("%d ", (int)temp[temp.size()/2]);
            }
            if(temp.size() == 1) break;
            // cout << endl;
            // temp.erase(temp.begin());
            // for(int i = 0; i < temp.size(); i++) {
            //     cout << temp[i] << " ";
            // }
            // cout << endl;
            vector<float>::iterator it = find(temp.begin(), temp.end(), a[b[del_index]-1]);
            // cout << "*it=" << *it << endl;
            temp.erase(it);
            // cout << "tempsize" << temp.size() << endl;
            // for(int i = 0; i < temp.size(); i++) {
            //     cout << temp[i] << " ";
            // }

            // cout << "a[b[del_index]]=" << a[b[del_index]] << " ";
            // a.erase(a.begin()+b[del_index]-1);
            // for(int i = 0; i < a.size(); i++) {
            //     cout << a[i] << " ";
            // }

            // cout << endl;
            del_index++;
        }
        cout << endl;
    }
    return 0;
}