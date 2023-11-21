#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    vector<int> v1, v2, v3;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    v2.push_back(1);
    v2.push_back(2);

    // v2 = v1;
    // // print
    // for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
    //     cout << *it << " ";
    // }
    // cout << endl;

    cout << v1[0] << v1.size() << endl;
    v1.erase(v1.begin()); // erase删的是迭代器对象
    cout << v1[0] << v1.size() << endl;

    // v2.assign(v1.begin(), v1.end());
    // // print
    // for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
    //     cout << *it << " ";
    // }
    // cout << endl;
    
    // v2.assign(7,3);

    // // print
    // for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++) {
    //     cout << *it << " ";
    // }
    // cout << endl;
    return 0;
}