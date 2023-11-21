#include<iostream>
#include<array>
#include<list>
using namespace std;

int main() {
    // list<int> values;
    // list<int> values(10);
    // list<int> values(10, 5);
    /* list<int> value1(10);
    list<int> values(value1); */
    /* int a[] = {1, 2, 3, 4, 5};
    list<int> values(a, a+5); */
    array<int, 5> arr{11, 12, 13, 14, 15};
    list<int> values(arr.begin()+2, arr.end());
    // values.insert(values.begin(), 20); // 头插入一个20
    // values.insert(values.end(), 2, 25); // 尾插入两个25
    // values.insert(values.begin(), arr.begin()+2, arr.end()); // 头插入arr[2:]
    values.insert(values.end(), {21,22}); // 尾插入初始化列表{elem}
    /* while(!values.empty()) {
        cout << values.front() << endl;
        values.pop_front();
    } */
    // values.reverse();
    for(auto p = values.rbegin(); p != values.rend(); p++) { cout << *p << endl;}
    // for(auto p = values.rend(); p != values.rbegin(); p--) { cout << *p << endl;} // 有问题
    return 0;
}