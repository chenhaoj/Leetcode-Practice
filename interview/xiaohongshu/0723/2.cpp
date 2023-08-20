#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

typedef struct tagInterval{
    int start;
    int end;
    tagInterval(int _start, int _end): start(_start), end(_end){}
}interval;

void PrintIntervalVec(vector<interval> vec) {
    // 打印
    int m = vec.size();
    for(int i = 0; i < m; i++) {
        cout << vec[i].start << vec[i].end << " ";
    }
    cout << endl;
}

// 重载比较运算符
bool cmp(const interval& a, const interval& b) {
    if(a.start == b.start) {
        return a.end - b.end;
    } else {
        return a.start - b.start;
    }
}

int getMaxProfit(vector<interval> vec, int k) {
    sort(vec.begin(), vec.end(), cmp);
    int n = vec.size();
    vector<int> prefixSum(n+1);
    // 记录前缀和，避免重复计算
    for(int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i-1] + vec[i-1].end - vec[i-1].start;
    }

    // 枚举左边界，二分找长度k所能包含的精华帖范围，获取收益
    int maxProfit = 0;
    for(int i = 0; i < n; i++) {
        int end = vec[i].start + k;
        int left = i, right = n-1;
        while(left <= right) {
            int mid = (left + right)/2;
            if(vec[mid].start <= end) {
                maxProfit = max(maxProfit, prefixSum[mid] - prefixSum[i] + min(end, vec[mid].end) - vec[mid].start);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return maxProfit;
}

int main() {
    int n, m, k = 0;
    cin >> n >> m >> k;
    unordered_map<int, int> um;
    vector<interval> v;
    int i = m;
    while(i--) {
        int s, e;
        cin >> s >> e;
        interval tmp = interval(s, e);
        v.push_back(tmp);
    }
    int res = getMaxProfit(v, k);
    cout << res << endl;
    return 0;
}