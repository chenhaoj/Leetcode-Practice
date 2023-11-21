#include<iostream>
#include<vector>
#include<algorithm> //注意要包含该头文件
using namespace std;
// int main()
// {
//   int nums[] = { 3 , 1 , 4 , 1 , 5 , 9 };
//   int num_to_find = 5 ;
//   int start = 0 ;
//   int end = 5 ;
//   int * result = find( nums + start, nums + end, num_to_find );
//   if ( result == nums + end ) 
//   {
//     cout<< "Did not find any number matching " << num_to_find << endl;
//   } 
//   else
//   {
//     cout<< "Found a matching number: " << *result << endl;
//   }
//   cout << distance(nums, result) << endl;
//   return 0 ;
// }

// int main(){
//     vector< int > v;
//     int num_to_find=25; //要查找的元素,类型要与vector<>类型一致
//     for ( int i=0;i<10;i++)
//         v.push_back(i*i);
//     vector< int >::iterator iter=std::find(v.begin(),v.end(),num_to_find); //返回的是一个迭代器指针
//     if (iter==v.end())
//       cout<< "ERROR!" <<endl;
//     else        //注意迭代器指针输出元素的方式和distance用法
//       cout<< "the index of value " <<(*iter)<< " is " << std::distance(v.begin(), iter)<<std::endl;
//     return 0;
// }

/* ---------------------------------------------------------------------------------
find_if函数：带条件的查找元素，容器元素类型是类的时候，不能使用find函数，只能通过find_if函数来实现。
find_if函数依次的遍历容器的元素，返回第一个使函数为true的元素的迭代器，如果查找失败则返回end迭代器
 */

// template < typename T>
// bool equal_3(T value){
//     return value==3;
// }
// int main(){
//     vector< int > vec;
//     vec.push_back(7);
//     vec.push_back(3);
//     vec.push_back(8);
//     vector< int >::iterator finda=find_if(vec.begin(),vec.end(),equal_3< int >);
//     if (finda!=vec.end())
//         cout<< "YES" <<*finda<<endl;
//     else
//         cout<< "ERROR" <<endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
struct Point {
    int x;
    int y;
};

struct PointFindByCoord: public std::binary_function<Point, Point, bool > {
    bool operator () ( const Point &obj1, const Point &obj2) const {
        return obj1.x == obj2.x && obj1.y == obj2.y;
    }
};

int main() {
    std::vector<Point> v;
    for ( int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            Point pt;
            pt.x = i;
            pt.y = j;
            v.push_back(pt);
        }
    }
    Point needFind;
    needFind.x = 4;
    needFind.y = 3;
    std::vector<Point>::iterator iter=std::find_if(v.begin(), v.end(), std::bind2nd(PointFindByCoord(), needFind));
    if (iter == v.end()) {
        // 未找到 
    }
    else
        std::cout << "the index of value Point(" << (*iter).x << ", " << (*iter).y
        << ") is " << std::distance(v.begin(), iter) << std::endl;
    return 0;
}