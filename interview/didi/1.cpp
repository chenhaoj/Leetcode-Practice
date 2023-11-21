#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> positions(n);
    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    int left = 1; // 最小距离的可能值
    int right = positions[n - 1] - positions[0]; // 最大距离的可能值
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int installed = 1; // 已安装的照明灯数量
        int current_position = positions[0]; // 当前安装的位置

        for (int i = 1; i < n; i++) {
            int distance = positions[i] - current_position;
            if (distance >= mid) {
                installed++;
                current_position = positions[i];
            }
        }

        if (installed >= k) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result << endl;
    return 0;
}
