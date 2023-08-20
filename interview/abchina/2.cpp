#include<iostream>
#include<vector>
using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.second < b.second;
}

int main() {
    string names[3] = {"王飞", "刘洋", "李丽"};
    string scores[3] = {"89,92,95,88,91", "92,96,81,90,92", "89,91,91,78,97"};
    vector<pair<string, int> > v;
    for(int i = 0; i < 3; i++) {
        int sum = 0;
        int score = 0;
        for(int j = 0; j < scores[i].size();) {
            cout << scores[i][j] << "  ";
            if(scores[i][j+1] == ',') {
                score += scores[i][j];
                j += 2;
            } else if(scores[i][j+2] == ',') {
                score += 100;
                j += 4;
            } else {
                int a = scores[i][j] - '0';
                int b = scores[i][j+1] - '0';
                score += a*10+b;
                j += 3;
            }
            sum += score;
            score = 0;
        }
        cout << names[i] << sum << endl;
        v.push_back(make_pair(names[i], sum));
        sum = 0;
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i].first <<  " ";
    }
    return 0;
}