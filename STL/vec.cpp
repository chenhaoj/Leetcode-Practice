#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> array(3, 0);
    array.insert(array.begin(), 1);
    for(int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    int j = 3;
    j ^= 1;
    cout << j << endl;
    return 0;
}