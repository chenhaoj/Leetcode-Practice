//template1.cpp 
#include <iostream>

// template<parameter-list> function-declaration
template<typename T>
void swap(T& a, T& b) {
    T tmp{a}; a = b; b = tmp;
}

// 模板函数显式初始化
template
void swap<float>(float& a, float& b);

// // 函数特征要加在函数定义范围function-declaration
// template<typename T> inline void swap(T &a, T &b) {
//     T tmp{a}; a = b; b = tmp;
// }

int main(int argc, char* argv[])
{
    int a = 2; int b = 3;
    swap(a, b); // 使用函数模板
    std::cout << "a=" << a << ", b=" << b << std::endl;
    double c = 1.1; double d = 2.2; 
    swap(c, d);std::cout << "c=" << c << ", d=" << d << std::endl;
    return 0;
}