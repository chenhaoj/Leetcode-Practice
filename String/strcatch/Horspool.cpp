#include <iostream>
#include <typeinfo>
using namespace std;

class Solution {
public:
    void preHorspool(int hors_d[], char *P, int Plen) {
        // cout << "su";
        for(int i = 0; i < Plen-1; i++) {
            hors_d[P[i]] = Plen-1-i;
        }

    }

    int horspool(char *T, int Tlen, char *P, int Plen, int hors_d[]) {
        int i, j;
        int pos = 0;
        while(pos <= Tlen-Plen) {
            j = Plen-1;//1
            while(j>=0 && T[pos+j]==P[j]) j--;
            if(j == -1) {
                return pos;
            }
            else {
                // pos += hors_d[T[pos+Plen-1]];
                pos += 2;
            }
        }
        return 0;
    }
};

int main() {
    Solution *sol = new Solution();
    // char text[5] = {'h', 'e', 'l', 'l', 'o'};
    char pattern[2] = {'l', 'l'};
    char text[5] = {'h', 'e', 'l', 'l', 'o'};
    // char pattern[6] = {'A', 'F', 'C', 'D', 'A', 'F'};
    
    // 初始化preHors表
    int hors_d[256];
    for(int i = 0; i < 256; i++) {
        hors_d[i] = sizeof(pattern);
    }

    // 测试
    sol->preHorspool(hors_d, pattern, 2);
    for(int i = 0; i < 2; i++) {
        cout << hors_d[pattern[i]];
    }
    cout << sol->horspool(text, 5, pattern, 2, hors_d);

    // cout << hors_d[0];
    // for(int i = 0; i < 4; i++) {
    //     cout << " " << hors_d[pattern[i]];
    // }
    return 0;
}