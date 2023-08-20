#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<sstream>
using namespace std;

/* ①cin---适用于输入数组以及字符串（不考虑字符串内部空格）
    注意点1：cin 可以连续从键盘读取数据
    注意点2：cin以空格、tab、换行符作为分割
    注意点3：cin从第一个非空格字符开始读取，直到遇到分隔符结束
    注：输出endl对象的时候，会输出一个换行符"\n"。
 */
// int main() {
//     int num;
//     cin >> num;
//     cout << num << endl;

//     // 批量输入
//     vector<int> nums(num);
//     for(int i = 0; i < num; i++) {
//         cin >> nums[i];
//     }

//     // 批量输出
//     for(auto it = nums.begin(); it != nums.end(); it++) {
//         cout << *it << " ";
//     }
//     return 0;
// }

/* ②getline()---适宜用它输入整行字符串（内含空格字符）
它会读取一行的字符串，直到遇到换行符结束。（遇到空格，也会读取）
 */
// int main() {
//     string s;
//     getline(cin, s);
//     cout << s << endl;
// }

/* ③getchar()---经常用于吃回车
    经常用于判断是否换行
 */
// int main() {
//     char ch;
//     // ch = getchar();
//     ch = cin.get();  // 还有写法: cin.get(ch);cin.get();getchar()
//     cout << ch << endl;
// }

/* ------------------具体样例------------------ */
/*  ①一维数组（固定数目）
 */
// int main() {
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     for(int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }
//     for(int i = 0; i < nums.size(); i++) {
//         cout << nums[i] << " ";
//     }
//     cout << endl;
// }

/* ②一维数组（不固定数目）
 */
// int main() {
//     vector<int> nums;
//     int num;
//     while(cin >> num) {
//         nums.push_back(num);
//         // 读到换行符，终止循环
//         // if(getchar() == '\n') {
//         if(cin.get() == '\n') {
//             break;
//         }
//     }

//     for(int i = 0; i < nums.size(); i++) {
//         cout << nums[i] << " ";
//     }
//     cout << endl;
// }

/* ③二维数组
 */
// int main() {
//     int m, n;
//     cin >> m >> n;
//     vector<vector<int> > nums(m, vector<int>(n)); // m*n
//     for(int i = 0; i < m; i++) {
//         for(int j = 0; j < n; j++) {
//             cin >> nums[i][j];
//         }
//     }

//     // 验证
//     for(int i = 0; i < m; i++) {
//         for(int j = 0; j < n; j++) {
//             cout << nums[i][j] << " ";
//         }
// 	cout << endl;
//     }
// }

/* ③附加创建二维数组方法
 */
// int main() {
//     int m, n;
//     cin >> m >> n;
//     int** a = (int**)malloc(m*sizeof(int));
//     if(a == NULL) {
//         return 0;
//     }
//     for(int i = 0; i < m; i++) {
//         a[i] = (int*)malloc(n*sizeof(int));
//         if(a[i] == NULL) { // 申请空间失败
//             while(--i > 0) {
//                 free(a[i]);
//             }
//             free(a);
//             return 0;
//         }
//     }
//     for(int i = 0; i < m; i++) {
//         for(int j = 0; j < n; j++) {
//             cin >> a[i][j];
//         }
//         cin.get();
//     }
    
//     for(int i = 0; i < m; i++) {
//         for(int j = 0; j < n; j++) {
//             cout << a[i][j];
//         }
//         cout << endl;
//     }
//     return 0;
// }

/* ④字符串（固定数目）
 */
// int main() {
//     int n;
//     cin >> n;
//     vector<string> strs(n);
//     for(int i = 0; i < n; i++) {
//         cin >> strs[i];
//     }
//     //验证
//     for(int i = 0; i < strs.size(); i++){
//         cout << strs[i] << " ";
//     }
//     cout << endl;
// }

/* ⑤字符串（不固定数目）
 */
// int main() {
//     vector<string> strs;
//     string str;
//     while(cin >> str) {
//         strs.push_back(str);
//         // 读到换行符，终止循环
//         // if(getchar() == '\n') {
//         if(cin.get() == '\n') {
//             break;
//         }
//     }
//     // 验证
//     for(int i = 0; i < strs.size(); i++) {
//         cout << strs[i] << " ";
//     }
//     cout << endl;
// }

/* ⑥字符串（一整行）
 */
// int main() {
//     vector<string> strs;
//     // 读入字符串
//     string s;
//     getline(cin, s);
//     // 处理字符串
//     int p = 0;
//     for(int q = 0; q < s.size(); q++) {
//         p = q;
//         while(s[p] != ';' && p < s.size()) {
//             p++;
//         }
//         string tmp = s.substr(q, p-q);
//         strs.push_back(tmp);
//         q = p;
//     }
//     // 验证
//     for(int i = 0; i < strs.size(); i++) {
//         cout << strs[i] << " ";
//     }
//     cout << endl;
// }

/* ⑦字符串流
 */
// int main() {
//     vector<string> strs;
//     string input;
//     while(getline(cin, input)) {
//         stringstream data(input);
//         int num = 0;
//         while(data >> num) {
//             cout << num << endl;
//         }
//         cout << endl;
//         if(cin.get() == '\n') 
//             break;
//     }
//     return 0;
// }

/* ⑧字符串流用","分隔
 */
// int main() {
//     string line;
//     while(getline(cin, line)) {
//         vector<string> strs;
//         stringstream ss(line);
//         string str;
//         while(getline(ss, str, ',')) {
//             strs.push_back(str);
//         }
//         for(auto& s : strs) {
//             cout << s << endl;
//         }
//         if(cin.get() == '\n') 
//             break;
//     }
//     return 0;
// }