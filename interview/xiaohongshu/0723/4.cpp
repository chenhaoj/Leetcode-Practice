/* 重写T2 */
#include<iostream>
#include<vector>
using namespace std;

struct interval {
    int start;
    int end;
};

bool cmp(const interval& a, const interval& b) {
    if(a.start == b.start) {
        return a.end - b.end;
    } else {
        return a.start - b.start;
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<interval> v(m);
    int i = m;
    while(i--) {
        int s, e;
        cin >> s >> e;
        interval tmp;
        tmp.start = s;
        tmp.end = e;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);
    vector<int> prefixSum(m+1);
    for(int i = 1; i <= m; i++) {
        prefixSum[i] = prefixSum[i-1] + v[i-1].end - v[i-1].start;
    }
    int maxProfit = 0;
    for(int i = 0; i < m; i++) {
        int end = v[i].start + k;
        int left = i, right = m-1;
        while(left <= right) {
            int mid = (left + right)/2;
            if(v[mid].start <= end) {
                maxProfit = max(maxProfit, prefixSum[mid] - prefixSum[i] + min(end, v[mid].end) - v[mid].start);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    cout << maxProfit << endl;
    return 0;
}