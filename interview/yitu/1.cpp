#include<iostream>
#include<vector>
using namespace std;

struct Book {
    string name;
    int price;
    Book(string bname, int bprice):name(bname), price(bprice){}
};

bool cmp(Book& a, Book& b) {
    return a.price < b.price;
}

int main() {
    int n;
    cin >> n;
    vector<Book> vec;
    while(n--) {
        string bname;
        int bprice;
        cin >> bname >> bprice;
        vec.push_back(Book(bname, bprice));
    }
    sort(vec.begin(), vec.end(), cmp);
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i].name << endl;
    }
    return 0;
}