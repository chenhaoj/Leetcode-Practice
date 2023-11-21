#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int chance = 1;
    int a = 0, b = 0;
    for (int i = 0; i < min(s.length(), t.length()); ++i) {
        if (s[i] == t[i]) {
            a++;
        } else {
            break;
        }
    }
    int old_a = a; // 老的前缀长度

    for (int i = 1; i <= min(s.length(), t.length()); ++i) {
        if (s[s.length() - i] == t[t.length() - i]) {
            b++;
        } else {
            break;
        }
    }
    int old_b = b; // 老的后缀长度
    int old_similarity = a * b; // 先计算老的相似度
    a = 0; b = 0;
    for (int i = 0; i < min(s.length(), t.length()); ++i) { // 尝试替换前缀
        if (s[i] == t[i]) {
            a++;
        } else {
            if(chance) {
                chance--;
                a++;
            } else
                break;
        }
    }
    int new_similarity_1 = a * old_b; //替换前缀的新相似度
    chance = 1;
    for (int i = 1; i <= min(s.length(), t.length()); ++i) { // 尝试替换后缀
        if (s[s.length() - i] == t[t.length() - i]) { 
            b++;
        } else {
            if(chance) {
                chance--;
                b++;
            } else 
                break;
        }
    }
    int new_similarity_2 = old_a * b; // 替换后缀的新相似度
    cout << max(new_similarity_1, new_similarity_2) << endl;
    return 0;
}
