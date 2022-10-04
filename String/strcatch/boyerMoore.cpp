#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
using namespace std;

class Solution {
public:
    int boyerMoore(char *text,int Tlen ,char *pattern,int Plen,int bmBc[],int bmGs[]) {
        int i,pos;
        pos=0;
        while(pos<=Tlen-Plen){
            for(i=Plen-1;i>=0&&pattern[i]==text[i+pos];i--);
            if(i < 0){
                return pos;
            }
            else{
                pos+=max(bmBc[text[i+pos]]-Plen+1+i,bmGs[i]);//MAX为求两个数中最大的一个，使用了宏定义#define MAX(x, y) (x)>(y) ? (x):(y)
            }
        }
        return 0;
    }

    // 计算坏字符数组
    void preBMbc(char *P, int plen, int bmBc[]) {
        // cout << "preBMbc success" << endl;
        int i;
        // 初始化：所有可能坏字符数组初始化为模式串长度plen
        for(i = 0; i < 256; i++) {
            bmBc[i] = plen;
        }
        // 更新：发生失配时，计算当前字符在模式串Pattern中最靠右的地方到串末尾的距离plen-1-i
        for(i = 0; i < plen; i++) {
            bmBc[P[i]] = plen-1-i;
        }
        // // // 测试
        // for(i = 0; i < plen; i++) {
        //     cout << P[i] << ":" << bmBc[P[i]] << endl;
        // }
    }
    
    // // 计算好后缀数组的相同前缀长度数组(求字符串相同前缀)
    // void suffix(char *P, int m, int suff[]) {
    //     /* 测试用例：
    //     1. AFCDAF
    //     2. AAFCDAF
    //     3. AFDFAF
    //     4. KAFCDAF */
    //     int pre, post; // prefix：前缀指针; postfix：后缀指针
    //     suff[m-1] = m;
    //     post = m-1;
    //     for(int i = m-2; i >= 0; i--) {
    //         // suffix更新
    //         if(P[post] == P[pre]) {
    //             post--;
    //         }
    //         else {
    //             // 相同前缀

    //         }
    //     }
    // }


    /*
    function:好后缀辅助数组（好后缀长度）求解前的预处理操作，即求出模式串中各个字符失配时相应的相同前缀长度
    Param:
    @pattern 需要匹配的字符串
    @suff 好后缀辅助数组的相同前缀长度数组
    @m 需要匹配的字符串长度
    */
    void suffix(char *pattern,int m,int suff[]) {
        // A F C D A(i) F(g) -> 0 2 0 0 0 6
        int f, g, i;
        suff[m-1]=m;
        g=m-1;
        for(i=m-2;i>=0;--i){
            if(i>g&&suff[i+m-1-f]<i-g)
                suff[i]=suff[i+m-1-f];
            else {
                if(i< g)
                    g=i;
                f=i;
                while(g>=0&&pattern[g]==pattern[g+m-1-f])
                    --g;
                suff[i]=f-g;
            }
        }

        // for(int i = 0; i < m; i++) {
        //     cout << suff[i] << " ";
        // }
    }

    // // 计算好后缀数组
    // void preBMgs(char *P, int bmGs[]) {

    // }

    /*
    function:好后缀数组求解方法
    Param:
    @pattern 需要匹配的字符串
    @bmGs 好后缀数组
    @m 需要匹配的字符串长度
    */
    void PreBmGs(char *pattern,int m,int bmGs[])
    {
        int i, j;
        int suff[m];  
        // 计算后缀数组
        suffix(pattern,m,suff);//看上一个函数
        // 先全部赋值为m，初始化
        for(i=0;i<m;i++){
            bmGs[i]=m;
        }
        // 当只存在后缀的相同子串时，如"ASDKGJOELHKSD"在"L"处失配时，第二、三个字符"SD"就是就是"L"的后缀"HKSD"的相同子串，子串必须是从第一个字符开始的
        j=0;
        for(i=m-1;i>=0;i--){
            if(suff[i]==i+1){
                for(;j<m-1-i;j++){
                    if(bmGs[j]==m)
                        bmGs[j]=m-1-i;
                }
            }
        }
        //当存在后缀的相同前缀时，如"HKSDKGJOELHKSD"在"L"处失配时，
        //第一、二、三、四个字符"HKSD"就是就是"L"的后缀"HKSD"的相同前缀，
        //相同前缀可以不从第一个字符开始，如"MHKSDKGJOELHKSD"在"L"处失配时，第二、三、四、五个字符"HKSD"就是就是"L"的后缀"HKSD"的相同前缀，
        for(i=0;i<=m-2;i++){
            bmGs[m-1-suff[i]]=m-1-i;
        }
        
        // for(int i = 0; i < 6; i++) {
        //     cout << bmGs[i] << " ";
        // }
    }
};

int main() {
    Solution *sol = new Solution();
    char text[5] = {'h', 'e', 'l', 'l', 'o'};
    char pattern[2] = {'l', 'l'};
    int bmBC[256] = {0};
    int bmGs[256] = {0};
    int suff[sizeof(pattern)];
    sol->preBMbc(pattern, sizeof(pattern), bmBC);
    // sol->suffix(pattern, sizeof(pattern), suff);
    sol->PreBmGs(pattern, sizeof(pattern), bmGs);
    cout << sol->boyerMoore(text, sizeof(text), pattern, sizeof(pattern), bmBC, bmGs);
    return 0;
}

/* 参考说明： https://www.freesion.com/article/6941134945/
 */