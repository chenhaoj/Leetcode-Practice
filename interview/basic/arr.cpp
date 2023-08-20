#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> array{1,2,3};
    vector<int> array_swap{6,7,8,9,10};
    // array_swap.swap(array); // 交换array_swap和array
    array_swap.assign(array.begin(), array.end()); // 先清空array_swap，再把array逐个复制到array_swap
    for(auto& x: array_swap) {
        cout << x << " ";
    }
    cout << endl;
    for(auto& x: array) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}