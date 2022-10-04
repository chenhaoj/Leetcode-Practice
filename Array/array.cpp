#include <iostream>
#include <vector>
using namespace std;

#define M 10
#define N 5

// 初始化一个 二维的matrix, 行M,列N,且值为0
vector<vector<int> > matrix(M,vector<int>(N));
// 初始化一个 二维的matrix, 行M,列N,且值自定义为data;
vector<vector<int> > matrix1(M,vector<int>(N, 1));

/* // 用大括号初始化二维数组
vector<vector<int> > matrix2{};
// 或者
vector<vector<int> > matrix3{{}};

//初始化列表
vector<vector<int> > matrix4{ {1},{1,1} };//学会用大括号初始化二维数组
// matrix4.push_back({ 1,2,1 });//插入 */
vector<int> sum(3,1);
vector<vector<string> > tickets = { {"MUC" "LHR"}, { "JFK" "MUC" }, { "SFO" "SJC" }, { "LHR" "SFO" } };

int main() {
    for(int i = 0; i < tickets.size(); i++) {
        cout << tickets[i][0] << endl;
    }
    return 0;
}
/* c++指针&new构建二维数组 */
void pointer_array() {
    int **p; // p[M][N]
    p = new int*[10];    //注意，int*[10]表示一个有10个元素的指针数组，10=M
    for (int i = 0; i < 10; ++i)
    {
        p[i] = new int[5];
    }
    // 释放
    for(int i = 0; i < 10; i++) 
        delete [] p[i];
    delete [] p;
}

/* C指针&malloc动态分配 */
/* // #include <stdlib.h>
void c_array() {
    int **p; // p[M][N]
    p = (int **)malloc(M * sizeof(int *));
    for(int i = 0; i < M; i++) {
        p[i] = (int *)malloc(N * sizeof(int));
    }
    
    // 释放
    for(int i = 0; i < M; i++)
        free(p[i]);
    free(p);
} */

/* initialize */
void vector_init() {
    vector<vector<int> > vec;

    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    vector<int> b;
    b.push_back(4);
    b.push_back(5);
    b.push_back(6);

    vec.push_back(a);
    vec.push_back(b);
}

/* 用resize初始化 */
void vector_init_resize() {
    //得到一个5行3列的数组
    //由vector实现的二维数组，可以通过resize()的形式改变行、列值
    int i,j;
    vector<vector<int> > array(5);
    for (i = 0; i < array.size(); i++)
        array[i].resize(3);

    for(i = 0; i < array.size(); i++)
    {
        for (j = 0; j < array[0].size();j++)
        {
            array[i][j] = (i+1)*(j+1);
        }
    }
}

/* 迭代器遍历 */
void reverse_with_iterator(vector<vector<int> > vec)
{
    if (vec.empty())
    {
        cout << "The vector is empty!" << endl;
        return;
    }

    vector<int>::iterator it;
    vector<vector<int> >::iterator iter;
    vector<int> vec_tmp;

    cout << "Use iterator : " << endl;
    for(iter = vec.begin(); iter != vec.end(); iter++)
    {
        vec_tmp = *iter;
        for(it = vec_tmp.begin(); it != vec_tmp.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}

/* 用.size()遍历 */
void reverse_with_index(vector<vector<int> > vec)
{
    if (vec.empty())
    {
        cout << "The vector is empty!" << endl;
        return;
    }

    int i,j;
    cout << "Use index : " << endl;
    for (i = 0; i < vec.size(); i++)
    {
        for(j = 0; j < vec[0].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
}
