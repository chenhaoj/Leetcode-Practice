#include<iostream>
#include<vector>
using namespace std;

struct Person {
    string name;
    int age;
    Person(string _name, int _age): name(_name), age(_age){}
};

// template<class ForwardIt, class T, class Compare>
// ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value, Compare comp);

bool person_cmp(const Person& a, const Person& b) {
    return a.age < b.age;
}

int main(int argc, char** argv) {
    vector<Person> people{
        {"Alice", 20},
        {"Bob", 25},
        {"Charlie", 30},
        {"David", 35},
        {"Eva", 40}
    };
    Person target = {"Bob", 25};
    auto it = lower_bound(people.begin(), people.end(), target, person_cmp);
    if (it != people.end() && it->name == target.name) {
        cout << "Found: " << it->name << ", " << it->age << endl;
    } else {
        cout << "Not found" << endl;
    }
    return 0;
}
