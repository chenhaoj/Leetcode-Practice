#include<iostream>
#include<vector>
using namespace std;

struct TIME {
    int hour;
    int minute;
    TIME(int h, int m):hour(h), minute(m){}
};

int string2time(string str) {
    int result = 0;
    int h = 0;
    for(int i = 0; i < 2; i++) {
        h = h * 10 + str[i] - '0';
    }
    int m;
    for(int i = 3; i < 5; i++) {
        m = m * 10 + str[i] - '0';
    }
    result = h * 60 + m;
    // cout << " " << result << endl;
    return result;
}

int main() {
    int m, n;
    cin >> m;
    vector<int> jin;
    for(int i = 0; i < m; i++) {
        string temp;
        cin >> temp;
        // cout << temp << "->" << string2time(temp) << " ";
        if(string2time(temp) >= string2time("12:00") && string2time(temp) <= string2time("14:00"))
            jin.push_back(string2time("14:00"));
        else if(string2time(temp) >= string2time("18:00") && string2time(temp) <= string2time("19:30"))
            jin.push_back(string2time("19:30"));
        else jin.push_back(string2time(temp));
        // cout << string2time(temp) << " ";
    }
    // for(int i = 0; i < jin.size(); i++) cout << jin[i] << " ";
    cin >> n;
    vector<int> chu;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        if(string2time(temp) >= string2time("12:00") && string2time(temp) <= string2time("14:00"))
            chu.push_back(string2time("12:00"));
        else if(string2time(temp) >= string2time("18:00") && string2time(temp) <= string2time("19:30"))
            chu.push_back(string2time("18:00"));
        else chu.push_back(string2time(temp));
        // cout << string2time(temp) << " ";
    }

    int result = 0;
    for(int i = 0; i < n; i++) {
        cout << "jin:" << jin[i] << "chu:" << chu[i] << endl;
        // if(chu[i] - jin[i] < 900) {
        //     continue; // 这里逻辑debug
        // }
        // result += chu[i] - jin[i] < 0 ? 0 : chu[i] - jin[i];
        result += chu[i] - jin[i];
        cout << result << endl;
    }
    cout << result << endl;
    return 0;
}