#include<iostream>
#include<vector>
using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     int result = 0;
//     for(int s = 0; s < n; s++) {
//         int temp;
//         cin >> temp;
//         bool flag = false;
//         for(int i = 2; i < pow(temp, 1.0/3.0) + 1; i++){
//             if(temp % i == 0 && temp != i) {
//                 temp = temp / i;
//                 for(int j = 2; j < sqrt(temp) + 1; j++) {
//                     if(temp % j == 0 && temp != j) {
//                         result++;
//                         flag = true;
//                         break;
//                     }
//                 }
//             }
//             if(flag) break;
//         }
//     }
//     cout << result << endl;
//     return 0;
// }

int main() {
    int n;
    cin >> n;
    vector<int> zhishu;
    vector<int> vec;
    int maxNum = -1;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
        maxNum = max(maxNum, temp);
    }
    // 筛选质数
    bool flag = true;
    for(int i = 2; i < maxNum; i++) {
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {
                flag = false;
                break;
            }
        }
        if(flag) zhishu.push_back(i);
        else flag = true;
    }
    int result = 0;
    for(int i = 0; i < vec.size(); i++) {
        bool find_flag = false;
        int temp = vec[i];
        for(int j = 0; j < zhishu.size(); j++) {
            if(temp % zhishu[j] == 0 && temp != zhishu[j]) {
                temp = temp / zhishu[j];
                for(int k = 0; k < zhishu.size(); k++) {
                    if(temp % zhishu[k] == 0 && temp != zhishu[k]) {
                        result++;
                        find_flag = true;
                        break;
                    }
                }
            }
            if(find_flag == true) break;
        }
    }
    cout << result << endl;
    return 0;
}