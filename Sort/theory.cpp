/*----------------------------Leetcode离线模板----------------------------*/
// #include<iostream>
// #include<vector>
// #include<set>

// using namespace std;

// class Solution{
// public:
    
// }

// int main(){

//     return 0;
// }


/*----------------------------排序算法----------------------------*/

// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;

// // int main() {
// // 	string str;
// // 	cin >> str;
// // 	cout << str;
// // 	for (int i = str.length()-1; i >= 0; i--) {
// // 		cout << str[i];
// // 	}
// //     system("pause");
// // 	return 0;
// // }

// int main(){
// 	float arrHeight[]={1.68,1.72,1.83,2.05,2.35,1.78,2.1,1.96};
// 	vector<float> vecHeight(arrHeight,arrHeight+sizeof(arrHeight)/sizeof(float));
// 	cout<<arrHeight<<endl;
// 	for(auto i:vecHeight){
// 		cout<<vecHeight[i];
// 	}
// 	system("pause");
// 	return 0;
// }


/*----------------------------二分查找法----------------------------*/
// #include<iostream>
// #include<algorithm>
// #include<cassert>
// #include<ctime>//ctime分函数和类。ctime功能是"把日期和时间转换为字符串"，ctime类的对象表示的时间是基于格林威治标准时间(GMT)的。
// #include<cmath>

// using namespace std;

// //生成随机队列
// int *generateRandomArray(int n, int rangeL, int rangeR){

//     assert( n>0 && rangeL <= rangeR);

//     int *arr = new int[n];

//     srand(time(NULL)); //使用当前时间进行随机数发生器的初始化  time_t time(time_t *t)若t是空指针，返回当前时间；否则返回当前时间的同时，将返回值赋予t指向的内存空间
//                                     //随机数发生器的初始化函数，和rand()配合使用产生伪随机数序列
//     for(int i = 0; i < n; i++)
//         arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
//     return arr;
// }

// //生成一个有序队列
// int *generateOrderedArray(int n){
//     assert( n > 0 );

//     int *arr = new int[n];

//     for(int i=0; i < n; i++)
//         arr[i]=i;
//     return arr;
// }

// //二分查找功能函数
// template<typename T>
// int binarySearch( T arr[], int n, T target ){

//     int l = 0, r = n - 1;//初试设置若为l=-1则是左开区间，r=n则是右开区间
//     while(l <= r){
//         //int mid = (l+r)/2;//这里可能会产生加法阈值溢出，是bug
// 		int mid = l + (r-l)/2;//这样是最完整的
//         if( arr[mid] == target )
//             return mid;
//         if(arr[mid] < target)
//             l = mid + 1;
//         else
//             r = mid - 1;
//     }

//     return -1;
// }
// int main() {

//     int n =  1000000;
//     int* data =generateOrderedArray(n);

//     clock_t  startTime=clock();
//     for( int i = 0 ; i < n ; i++)
//         assert( i == binarySearch(data, n , i));//找到了就没有异常，这里相当于从0到n全部查找一遍
//     clock_t endTime = clock();

//     cout<<"binarySearch test complete."<<endl;
//     cout<<"Time cost:"<<double(endTime - startTime)/CLOCKS_PER_SEC<<"s"<<endl;
//     return 0;
// }


/*----------------------------查找----------------------------*/
/*set集合的使用*/
// #include<iostream>
// #include<vector>
// #include<set>
// #include<unordered_set>      //O(n)

// using namespace std;

//时间复杂度:O(nlogn)
//空间复杂度:O(n)
// class Solution(){
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2){

//         // //数组元素存入一个集合
//         // set<int> record;
//         // unordered_set<int> record;
//         // for(int i = 0 ; i < nums1.size() ; i++)
//         //     record.insert(nums1[i]);
//         // 简化写法，直接用容器类的构造方法
//         // O(nlogn)
//         set<int> record(nums1.begin(), nus1.end());
//         // unordered_set<int> record(nums1.begin(), nus1.end());

//         // 开一个集合用来存查找结果
//         // O(nlogn)
//         set<int> resultSet;
//         // unordered_set<int> resultSet;
//         for(int i = 0 ; i < nums2.size() ; i++ )
//             if(record.find(nums2[i]) != record.end())
//                 resultSet.insert( nums2[i]);

//         // //把set转换成vector返回
//         // vector<int> resultVector;
//         // //遍历容器类，通常需要使用容器类的迭代器
//         // for( set<int>::iterator iter = resultSet.begin() ; iter != resultSet.end(); iter ++)
//         //     resultVector.push_back( *iter );

//         // return resultVector;
//         //简化写法，同理直接用构造函数
//         //O(n)
//         return vector<int>(resultSet.begin(), resultSet.end());
//     }
// }

// int main(){

//     return 0;
// }

/*map字典的使用*/
/*T350*/
// #include<iostream>
// #include<vector>
// #include<map>

// using namespace std;

// class Solution{
//     public:
//         vector<int> intersect(vector<int> & nums1, vector<int> & nums2){
        
//         map<int, int> record;
//         for( int i = 0; i < nums1.size(); i++)
//             record[ nums1[i] ] ++;

//         vector<int> resultVector;
//         for( int i = 0; i < nums2.size(); i++) {
//             if( record[ nums2[i] ] > 0 )
//                 resultVector.push_back( nums2[i] );
//                 record[ nums2[i] ]--;
//         }

//         return resultVector;
//     }
// };

// int main(){
//     return 0;
// }

/*T350修改*/
/*哈希表能实现算法最优，时间复杂度达到O(1)，但存在缺点:会失去数据的顺序性*/
/*二分搜索树(平衡)，可以保持数据的顺序性，算法时间复杂度可以保持在O(logn)*/
/*C++语言中，map和set的底层实现是平衡二叉树，unordered_map和unordered_set的底层实现是哈希表*/
/*与set同理，只需要将头文件和map改成unordered_map即可*/
// #include<iostream>
// #include<vector>
// #include<map>
// // #include<unordered_map>  //O(n)

// using namespace std;
// //时间复杂度:O(nlogn)
// //空间复杂度:O(n)
// class Solution{
//     public:
//         vector<int> intersect(vector<int> & nums1, vector<int> & nums2){
//         // O(nlogn)
//         map<int, int> record;
//         // unordered_map<int, int> record;
//         for( int i = 0; i < nums1.size(); i++)
//             if( record.find(nums1[i]) == record.end() )
//                 record.insert( make_pair(nums1[i], 1) );
//             else
//                 record[nums1[i]]++;
//         //O(nlogn)
//         vector<int> resultVector;
//         for( int i = 0; i < nums2.size(); i++) {
//             if( record.find( nums2[i] ) != record.end() && record[ nums2[i] ] > 0 )
//                 resultVector.push_back( nums2[i] );
//                 record[ nums2[i] ]--;
//             if( record[nums2[i]] == 0 )
//                 record.erase( nums2[i] );
//         }

//         return resultVector;
//     }
// };

// int main(){
//     return 0;
// }

/*----C++库标准中的map初始化为空，当你访问一个数据之后，默认添加到map中，想要擦除只有map.erase(element)----*/
/*----map中一个键是0和没有这个键是两个概念，注意区分----*/
// #include<iostream>
// #include<map>

// using namespace std;

// int main(){
    
//     map<int, int> myMap;

//     if(myMap.find(42) == myMap.end())
//         cout<<"Can not find element 42"<<endl;
//     else
//         cout<<"Element 42 is in the map"<<endl;
    
//     cout<<myMap[42]<<endl;

//     if (myMap.find(42) == myMap.end())
//         cout << "Can not find element 42" << endl;
//     else
//         cout << "Element 42 is in the map" << endl;

//     myMap[42]++;
//     cout<<myMap[42]<<endl;

//     myMap[42]--;
//     cout<<myMap[42]<<endl;

//     myMap.erase(42);
//     if (myMap.find(42) == myMap.end())
//         cout << "Can not find element 42" << endl;
//     else
//         cout << "Element 42 is in the map" << endl;

//     return 0;
// }

/*查找练习题:
            242.Valid Anagram————判断字符串是否是另一个字符串的翻转。      注意：考虑"空串"和"字符集"
            202.Happy Number
            290.Word pattern
            205.Isomorphic Strings
            451.Sort Characters By Frequency
----------*/

/*查找经典问题*/
/*T1：法一：暴力搜索
      法二：对撞指针
      法三：查找表
      */

// //法三:查找表
// #include<iostream>
// #include<vector>
// #include<cassert>
// #include<unordered_map>

// using namespace std;

// class Solution{
//     public:
//         vector<int> twoSum(vector<int>& nums, int target) {
            
//             unordered_map<int, int> record;
//             for( int i = 0; i < nums.size(); i++) {
                
//                 int complement = target - nums[i];
//                 if( record.find(complement) != record.end() )
                    
//             }
//         }
// };

/*----------------T15 3Sum------------------------*/
// #include<iostream>
// #include<cstring>
// #include<vector>
// using namespace std;

// class Solution {
// public:
//     vector<vector<int> > threeSum(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         vector<vector<int> > ans;
//         // 枚举 a
//         for (int first = 0; first < n; ++first) {
//             // 需要和上一次枚举的数不相同
//             if (first > 0 && nums[first] == nums[first - 1]) {
//                 continue;
//             }
//             // c 对应的指针初始指向数组的最右端
//             int third = n - 1;
//             int target = -nums[first];
//             // 枚举 b
//             for (int second = first + 1; second < n; ++second) {
//                 // 需要和上一次枚举的数不相同
//                 if (second > first + 1 && nums[second] == nums[second - 1]) {
//                     continue;
//                 }
//                 // 需要保证 b 的指针在 c 的指针的左侧
//                 while (second < third && nums[second] + nums[third] > target) {
//                     --third;
//                 }
//                 // 如果指针重合，随着 b 后续的增加
//                 // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
//                 if (second == third) {
//                     break;
//                 }
//                 if (nums[second] + nums[third] == target) {
//                     ans.push_back({nums[first], nums[second], nums[third]});
//                 }
//             }
//         }
//         return ans;
//     }
// };


// /*----------------leetcode刷题记录------------------*/
// #include<iostream>
// #include<vector>
// #include<limits.h>
// #include<stdlib.h>

// class Solution{
//     public:
//         int divide(int dividend, int divisor){
//             //先考虑三种特殊情况
//             if(dividend == 0) return 0;
//             if(divisor == 1) return dividend;
//             if(divisor == -1){
//                 if(dividend > INT_MIN) return -dividend;
//                 else return INT_MAX;
//             }
//             //开空间用来做递归，允许参数调整
//             long dividend_ = dividend;
//             long divisor_ = divisor;
//             int sign = 1;
//             if((dividend_ > 0 && divisor_ < 0) || (dividend_ < 0 && divisor_ > 0)) sign = -1;
//             dividend_ = dividend_ > 0 ? dividend_ : (-dividend_);
//             divisor_ = divisor_ > 0 ? divisor_ : (-divisor_);
//             long res = div(dividend_, divisor_);
//             if(sign > 0)return res > INT_MAX ? INT_MAX : res;
//             else return -res;
//         }

//         int div(long dividend_, long divisor_){
//             if(dividend_ < divisor_) return 0;
//             long count = 1;
//             long td = divisor_;//开一个divisor_的可变替身
//             while((td + td) <= dividend_){
//                 count += count;
//                 td += td;
//             }
//             return count + div(dividend_ - td, divisor_);
//         }
// };

// int main()
// {
//     Solution *test = new Solution();
//     std::cout << test->divide(10 , 3);
//     system("pause");
//     return 0;
// }


// #include<iostream>
// #include<cstring>
// #include<vector>
// using namespace std;

// class Solution{
// public:
//     int uniquePathsWithObstacles(vector<vector<int> > & obstacleGrid){
//         if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0 || obstacleGrid[0][0] == 1){
//             return 0;
//         }
//         vector<int> flag(obstacleGrid[0].size());
//         flag[0] = obstacleGrid[0][0] == 1 ? 0 : 1;
//         for (int i = 0; i < obstacleGrid.size(); i++){
//             for(int j = 0; j < obstacleGrid[0].size(); j++){
//                 if(obstacleGrid[i][j] == 1){
//                     flag[j] = 0;
//                 }
//                 else if(j - 1 >= 0 && obstacleGrid[i][j - 1] != 1){
//                 flag[j] += flag[j - 1];
//                 }
//             }
//         }
//         return flag.back();
//     }
// };

// int main(void){
//     return 0;
// }


/*
 * 数字序列求和
 */
/*
#include<iostream>
using namespace std;
int main()
{
	int sum=0,value=0;
	//读取数据直到遇到文件尾，计算所有读入的值的和
	while(cin>>value)
	{
		sum+=value;
	}
	cout<<"Sum is: "<<sum<<endl;
	system("pause");
	return 0;
}
*/

/*
 * 统计顺序出现的数字序列中各数的次数
*/
/*
#include<iostream>
int main()
{
	int currVal=0,val=0;
	if(std::cin>>currVal)
	{
		int cnt=1;//cnt记录次数
		while(std::cin>>val)//用while循环反复从标准输入流读取数据
		{
			if(val==currVal)++cnt;
			else
			{
				std::cout<<currVal<<" occurs "<<cnt<<" times "<<std::endl;
				currVal=val;
				cnt=1;
			}//循环至此结束，但这样最后一个数据无法打印
		}
		std::cout<<currVal<<" occurs "<<cnt<<" times "<<std::endl;
	}
	system("pause");
	return 0;
}
*/
/*
 *自动类型转换
 */
/*
#include<iostream>
int main()
{
	unsigned u=10;
	int i=10;
	std::cout<<u-i<<std::endl;
	std::cout<<i-u<<std::endl;
	system("pause");
	return 0;
}
*/
/*
 *输出测试
 */

// #include<iostream>
// #include<stdlib.h>
// int main()
// {
// 	double Double=9999.99;
// 	std::cout<<Double<<"\n"<<std::endl;
// 	system("pause");
// 	return 0;
// }

// /*----------------leetcode刷题记录------------------*/
// #include <iostream>
// #include <vector>
// #include <limits.h>
// #include <stdlib.h>

// class Solution
// {
// 	public:
// 		int divide(int dividend, int divisor)
// 		{
// 			if (dividend == 0)
// 				return 0;
// 			if (divisor == 1)
// 				return dividend;
// 			if (divisor == -1)
// 			{
// 				if (dividend > INT_MIN)
// 					return -dividend; // 只要不是最小的那个整数，都是直接返回相反数就好啦
// 				return INT_MAX;		  // 是最小的那个，那就返回最大的整数啦
// 			}
// 			long a = dividend;
// 			long b = divisor;
// 			int sign = 1;
// 			if ((a > 0 && b < 0) || (a < 0 && b > 0))
// 			{
// 				sign = -1;
// 			}
// 			a = a > 0 ? a : -a;
// 			b = b > 0 ? b : -b;
// 			long res = div(a, b);
// 			if (sign > 0)
// 				return res > INT_MAX ? INT_MAX : res;
// 			return -res;
// 		}
// 		int div(long a, long b)
// 		{ // 似乎精髓和难点就在于下面这几句
// 			if (a < b)
// 				return 0;
// 			long count = 1;
// 			long tb = b; // 在后面的代码中不更新b
// 			while ((tb + tb) <= a)
// 			{
// 				count = count + count; // 最小解翻倍
// 				tb = tb + tb;		   // 当前测试的值也翻倍
// 			}
// 			return count +div(a - tb, b);
// 		}
// };

// int main()
// {
// 	Solution *test = new Solution();
// 	std::cout << test->divide(10, 3);
// 	// system("pause");
// 	return 0;
// }

/*---------------------------------------------------------------取自原AL-Pra.cpp文件----------------------------------------------------------------*/
// #include<iostream>
// #include<vector>
// #include<cmath>
// #include<algorithm>
// #include<set>
// using namespace std;

//最粗暴解决斐波那契数列问题O(2^n)
// int fib(int N){
//     if(N == 1 or N == 2) return 1;
//     return fib(N - 1) + fib(N - 2);
// }

//递归解决斐波那契额数列问题O(n)
// int helper(std::vector<int>& memo, int n){
//     if(n == 1 or n == 2) return 1;
//     if(memo[n] != 0) return memo[n];
//     memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
//     return memo[n];
// }

// int fib(int N){
//     if(N < 1) return 0;
//     std::vector<int> memo(N + 1, 0);
//     return helper(memo, N);
// }

// int main(){
//     int n = 20;
//     std::cout<<fib(n);
//     return 0;
// }

//自底向上dp解决斐波那契数列问题O(n)
// int fib(int N){
//     std::vector<int> dp(N + 1, 0);
//     dp[1] = dp[2] = 1;
//     for(int i = 3; i < N + 1; i++)
//         dp[i] = dp[i - 1] + dp[i - 2];
//     return dp[N];
// }

// int main(){
//     int n = 20;
//     std::cout<<fib(n);
//     return 0;
// }

//自底向上基础上降低空间复杂度到O(1)
// int fib(int n){
//     if(n == 2 or n == 1)return 1;
//     else{
//         int pre = 1;
//         int cur = 1;
//         for(int i = 3; i <= n; i++){
//             int sum = pre + cur;
//             pre = cur;
//             cur = sum;
//         }
//         return cur;
//     }
// }

// int main(){
//     int n = 20;
//     std::cout << fib(n);
//     return 0;
// }

//------------动态规划之凑零钱问题----------------//
//暴力解法，对C++语法不清晰
// int min(int a, int b){
//     if(a < b) return a;
//     else return b;
// }

// int dp(int n, int array[]){
//     if(n == 0) return 0;
//     if(n < 0) return -1;
//     int res = 9999;
//     for(int i = 0; i < sizeof(array); i++){
//         int subproblem = dp(n - array[i], array);
//         if(subproblem == -1) continue;
//         int res = min(res, 1 + subproblem);
//     }
//     return res;
// }

// int coinChange(int amount, int array[]){
//     return dp(amount, array);
// }

// int main(){
//     int array[3] = {1, 2, 5};
//     int amount = 11;
//     std::cout << coinChange(amount, array);
//     return 0;
// }

//用dp数组的迭代解法
//dp[i]=x 表示，当目标金额为i时，至少需要x枚硬币
//代码有误，测试用例dp[11]=6错误
// int min(int a, int b){
//     if(a < b) return a;
//     else return b;
// }

// int coinChange(std::vector<int>& coins, int amount){
//     std::vector<int> dp(amount + 1, amount + 1);
//     dp[0] = 0;
//     for(int i = 0; i < dp.size(); i++){
//         for(int coin = 0; coin < coins.size(); coin++){
//             if(i - coins[coin] < 0) continue;
//             dp[i] = min(dp[i], 1 + dp[i - coins[coin]]);
//             std::cout << dp[i];
//         }
//     }
//     return (dp[amount] == amount + 1) ? -1 : dp[amount];
// }

// int main(){
//     std::vector<int> coins(3, 0);
//     coins[0] = 1;
//     coins[1] = 2;
//     coins[3] = 5;
//     int amount = 11;
//     std::cout << coinChange(coins, amount);
//     return 0;
// }

// int main(){
//     int sum = 0, value = 0;
//     while(std::cin >> value){
//         sum += value;
//     }
//     std::cout << "Sum is :" << sum << std::endl;
//     return 0;
// }

// template <typename T>
// T square(T x){
//     return x*x;
// }

// int main(){
//     std::cout << square<int>(5) << std::endl;
//     std::cout << square<double>(5.5) << std::endl;
//     return 0;
// }

/*------------------Leetcode 160--------------------*/
// // 解法1：算法时间复杂度O(nlogn),空间复杂度O(n)
// struct ListNode{
//     int val; //节点中存储的数据
//     ListNode *next; //指向下一个节点的指针
//     ListNode(int x):val(x),next(NULL){} //构造函数
// };

// // int list_length(ListNode *)
// class Solution{
//     public:
//         ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
//             std::set<ListNode*> check_set; //判断相同节点的集合
//             ListNode *result = NULL; //存储两链表的交点
//             while(headA){ //遍历链表A
//                 check_set.insert(headA); //将链表A中的节点地址添加到check_set
//                 headA = headA->next;
//             }
//             while(headB){ //遍历链表B
//                 if(check_set.find(headB) != check_set.end()){ //找到重复的节点
//                     result = headB; //第一个重复的节点即为链表相交的节点，将它存储至result
//                     break; //跳出循环
//                 }
//                 headB = headB->next;
//             }
//             return result; //函数返回result
//         }
// };

// // 解法2：算法时间复杂度O(n),空间复杂度O(1)
// int list_length(ListNode *head){ //待求长度的链表头结点指针
//     int length = 0; //存储链表长度
//     while(head){
//         head = head->next; //每遍历一个节点，length++
//         length++;
//     }
//     return length;
// }

// ListNode *move_pointer(ListNode *head, int count){
// //链表头结点指针head与移动的节点数count
//     for(int i = 0; i < count; i++){
//     //将head指针向前移动count个节点
//         head = head->next;
//     }
//     return head; //返回移动后的指针head
// }

// class Solution{
//     public:
//         ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
//             int lengthA = list_length(headA); //计算链表A的长度
//             int lengthB = list_length(headB); //计算链表B的长度
//             if( lengthA > lengthB ){ //比较lengthA与lengthB的大小
//                 //移动较长链表headA,使指针headA与headB对齐
//                 headA = move_pointer(headA, lengthA - lengthB);
//             }
//             else{ //移动较长链表headB,使指针headB与headA对齐
//                 headB = move_pointer(headB, lengthB - lengthA);
//             }
//             ListNode *result = NULL; //存储交点地址
//             while( headA && headB ){ //同时向前移动headA与headB
//                 if( headA == headB ){ //当headA与headB相等时
//                     result = headA; //该节点即为两链表的交点，将它的地址存储至result
//                     break; //跳出循环
//                 }
//                 headA = headA->next;
//                 headB = headB->next;
//             }
//             return result; //返回result,两个链表的交点地址
//         }
// };

// int main(){
//     ListNode a(4);
//     ListNode b(1);
//     ListNode c(5);
//     ListNode d(0);
//     ListNode e(1);
//     ListNode f(8);
//     ListNode g(4);
//     ListNode h(5);
//     a.next = &b;
//     b.next = &f;
//     c.next = &d;
//     d.next = &e;
//     e.next = &f;
//     f.next = &g;
//     g.next = &h;
//     Solution solve;
//     ListNode *result = solve.getIntersectionNode(&a, &c);
//     std::cout << result->val;
//     return 0;
// }

/*------------------Leetcode 946--------------------*/
/* 合法出栈序列 解题思路：综合利用队列先进先出和堆栈先进后出的属性特征，进行模拟实验
   为此需要开辟一个栈辅助完成。
   实验规则：当栈顶与popped出栈队列头相同时，栈顶出栈；否则pushed入栈队列入栈；最后判断栈是否为空；
           若栈为空，则是合法序列；栈不为空，则是非法序列。
*/
// #include<iostream>
// #include<stack>
// #include<stdio.h>
// #include<vector>
// class Solution{
//     public:
//         bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped){ //pushed入栈队列，popped出栈队列
//             std::stack<int> S; //模拟入栈和出栈的过程
//             int index = 0; //当前正在判断的出栈序列元素的下标
//             for(int i = 0; i < pushed.size(); i++){ //遍历入栈序列中的每个元素
//                 S.push(pushed[i]); //每遍历一个元素即将该元素push入栈S
//                 while( !S.empty() && popped[index] == S.top()){ //栈顶与队头是否相等
//                     //如果相等，同时弹出栈顶元素与队列头部元素
//                     //直到栈空或栈顶与队列头部元素不同
//                     S.pop(); //弹出栈顶元素
//                     index++; //弹出队列头部元素
//                 }
//             }
//             if(!S.empty()){ //栈不为空标识出栈序列不合法返回false
//                 return false;
//             }
//             return true; //若栈为空，出栈序列合法，返回true
//         }
// };

// int main(){
//     std::vector<int> pushed;
//     std::vector<int> popped;
//     pushed.push_back(1);
//     pushed.push_back(2);
//     pushed.push_back(3);
//     pushed.push_back(4);
//     pushed.push_back(5);

//     popped.push_back(3);
//     popped.push_back(2);
//     popped.push_back(5);
//     popped.push_back(4);
//     popped.push_back(1);
    
//     Solution solve;
//     std::cout << solve.validateStackSequences(pushed, popped);
//     return 0;
// }

/*------------------Leetcode 452--------------------*/
// 贪心算法 射击气球
// #include<iostream>
// #include<vector>
// #include<algorithm>

// bool cmp(const std::vector<int> &a, const std::vector<int> &b){
//     return a[0] < b[0]; //比较两个气球的左端点
// }

// class Solution{
// public:
//     int findMinArrowShots(std::vector<std::vector<int> > &points){
//         if(points.size() == 0){ //特殊的空数据判断
//             return 0;
//         }
//         std::sort(points.begin(), points.end(), cmp); //对气球从左到右进行排序
//         int arrow_count = 1; //存储射击次数，初始化为1
//         int interval_right = points[0][1]; //存储射击区间的右端点，初始化为第1个气球的右端点
//         for(int i = 1; i < points.size(); i++){ //遍历各个气球
//             if(interval_right >= points[i][0]){
//                 // 射击区间的右端点大于等于遍历气球的左端点，在此区间中可以射击到该气球
//                 if(interval_right > points[i][1]){ //当前区间右端点大于遍历气球的右端点
//                     interval_right = points[i][1]; //当前射击区间的右端点更新为遍历气球的右端点
//                 }
//             }
//             else{ // 射击区间的右端点小于遍历气球的左端点，区间与新的气球没有交集
//                 arrow_count++;  //增加一次射击
//                 interval_right = points[i][1]; //设置新的射击区间右端点为气球右端点
//             }
//         }
//         return arrow_count; //返回arrow_count为最终的射击次数
//     }
// };

// int main(){
//     std::vector<std::vector<int> > points;
//     std::vector<int> p0,p1,p2,p3;
//     p0.push_back(10);p0.push_back(16);points.push_back(p0);
//     p1.push_back(2);p1.push_back(8);points.push_back(p1);
//     p2.push_back(1);p2.push_back(6);points.push_back(p2);
//     p3.push_back(7);p3.push_back(12);points.push_back(p3);
//     Solution solve;
//     std::cout << solve.findMinArrowShots(points);
//     return 0;
// }

/*------------------Leetcode 55--------------------*/
// 贪心算法 跳跃游戏
// #include<iostream>
// #include<vector>

// class Solution{
//     public:
//         bool canJump(std::vector<int>& nums){
//             std::vector<int> jump; //保存每个位置可以到达的最远位置
//             for(int i = 0; i < nums.size(); i++){
//                 jump.push_back(i + nums[i]); //初始化jump数组，jump[i]=i+nums[i]
//             }
//             int index = 0; //存储当前位置
//             int max_jump = jump[0]; //存储当前可以到达的最远位置，初始化为jump[0]
//             while(index < jump.size() && index <= max_jump){
//                 if(jump[index] > max_jump){
//                 //如果可达到的最远距离max_jump小于jump[index]
//                     max_jump = jump[index]; //将max_jump更新为jump[index]
//                 }
//                 index++; //使用index遍历jump数组
//             }
//             if(index == jump.size()){ //index为数组长度
//                 return true; //该问题有解，返回true
//             }
//             return false; //否则返回false
//         }
// };

// int main(){
//     int a[7] = {2, 4, 2, 3, 1, 0, 0};
//     std::vector<int> nums(a, a+7);
//     // nums.push_back(2);
//     // nums.push_back(4);
//     // nums.push_back(2);
//     // nums.push_back(3);
//     // nums.push_back(1);
//     // nums.push_back(0);
//     // nums.push_back(0);
//     Solution solve;
//     std::cout << solve.canJump(nums);
//     return 0;
// }

/*------------------Leetcode 473--------------------*/
// 回溯搜索+剪枝优化 火柴拼正方形
// 剪枝优化方法：1、排除火柴数量<4和火柴总长度mod4≠0的样例；
//            2、对火柴长度降序排列，以减少回溯次数
// #include<iostream>
// #include<vector>
// #include<algorithm>

// class Solution{
// public:
//     bool makesquare(std::vector<int> &nums){
//         if(nums.size()<4)return false;
//         int sum = 0;
//         for(int i = 0; i < nums.size(); i++){
//             sum += nums[i];
//         }
//         if(sum % 4)return false;
//         sort(nums.rbegin(), nums.rend());
//         int bucket[4]={0};
//         return backtrack(0, nums, sum/4, bucket);
//     }
// private:
//     bool backtrack(int i, std::vector<int> &nums, int edge, int bucket[]){
//         if(i >= nums.size())return true;
//         for(int j = 0; j < 4; j++){
//             if(bucket[j] + nums[i] > edge){
//                 continue;
//             }
//             bucket[j] += nums[i];
//             if(backtrack(i+1, nums, edge, bucket)){
//                 return true;
//             }
//             bucket[j] -= nums[i];
//         }
//         return false;
//     }
// };

// int main(){
//     int a[6] = {1, 2, 3, 4, 5, 5};
//     std::vector<int> nums (a, a+6);
//     Solution solve;
//     std::cout << solve.makesquare(nums);
//     return 0;
// }

/*------------------Leetcode 236--------------------*/
// 二叉树 最近的公共祖先
// #include<iostream>
// #include<vector>

// struct TreeNode{
//     int val; //节点中存储的数据
//     TreeNode *left; //指向左子树的指针
//     TreeNode *right; //指向右子树的指针
//     TreeNode(int x):val(x),left(NULL),right(NULL){} //构造函数
// };

// void dfs_search(TreeNode *node, //当前正在搜索的节点
//                 TreeNode *search, //待查找路径的节点
//                 std::vector<TreeNode *> &stack, //存储节点路径的栈
//                 std::vector<TreeNode *> &path){ //存储待最后找到的search节点路径
//     if(node == NULL){ //如果为null，则返回并结束递归
//         return;
//     }
//     stack.push_back(node); //将当前访问的节点压入栈中
//     if(node == search){ //判断节点是否为所寻找的节点
//         path = stack; //当前stack中存储的即为结果路径，将其存储到path中
//         return; //返回，递归结束
//     }
//     dfs_search(node->left, search, stack, path); //递归遍历node节点的左子树
//     dfs_search(node->right, search, stack, path); //递归遍历node节点的右子树
//     stack.pop_back(); //为了保证后续栈中存储的节点为根节点到当前遍历节点路径上的节点，将遍历完成的这个节点弹出栈
// }

// class Solution{
// public:
//     TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
//         std::vector<TreeNode *> p_path; //存储p节点路径
//         std::vector<TreeNode *> q_path; //存储q节点路径
//         std::vector<TreeNode *> stack; //求路径时使用的栈stack

//         dfs_search(root, p, stack, p_path); //求出p节点的路径
//         stack.clear(); //清空栈中的元素
//         dfs_search(root, q, stack, q_path); //求出q节点的路径

//         TreeNode *common; //存储两节点的最近公共祖先
//         int i = 0;
//         while(i < p_path.size() && i < q_path.size()){ //两条路径均为遍历完成
//             if(p_path[i] == q_path[i]){ //寻找两条路径上最后一个相同的节点
//                 common = p_path[i]; //将它存储至common中
//             }
//             i++;
//         }
//         return common; //返回common，即p、q的最近公共祖先
//     } //返回p节点与q节点的最近公共祖先节点
// };

// int main(){
//     TreeNode a(3), b(5), c(1), d(6), e(2), f(0), g(8), h(7), i(4);
//     a.left = &b;
//     a.right = &c;
//     b.left = &d;
//     b.right = &e;
//     c.left = &f;
//     c.right = &g;
//     e.left = &h;
//     e.right = &i;
//     Solution solve;
//     TreeNode *common = solve.lowestCommonAncestor(&a, &d, &h);
//     //求d、h的最近公共祖先
//     std::cout << common->val;
//     //输出测试值应为5
//     return 0;
// }

/*------------------Leetcode 199--------------------*/
// 二叉树 侧面观察二叉树
// #include<iostream>
// #include<vector>
// #include<queue>

// struct TreeNode{
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x):val(x),left(NULL),right(NULL){}
// };

// class Solution{
// public:
//     std::vector<int> rightSideView(TreeNode* root){
//         std::vector<int> watch; //存放从右侧观察的结果的数组
//         if(!root){ //如果root为空，直接返回空的watch数组
//             return watch;
//         }
//         //初始化遍历使用的队列que，队列元素是一个节点指针与整数层数绑定的pair
//         std::queue<std::pair<TreeNode*, int> >que;
//         que.push(std::make_pair(root, 0));
//         //层次遍历
//         while(!que.empty()){
//             //取出队首元素
//             TreeNode *node = que.front().first; //获得待搜索节点的地址
//             int level = que.front().second;
//             que.pop(); //将遍历过的节点出队
            
//             if(watch.size() <= level){ //如果取出的节点是这一层第一个节点
//                 watch.push_back(0); //watch数组长度不够
//             }
//             watch[level] = node->val; //更新watch数组中的最后一个元素为该节点的值
//             //如果该节点有左右孩子，将左右孩子与所在层次绑定放入队列，孩子节点层次为该节点层次+1
//             if(node->left){
//                 que.push(std::make_pair(node->left, level + 1));
//             }
//             if(node->right){
//                 que.push(std::make_pair(node->right, level + 1));
//             }
//         }
//         return watch;
//     }
// };

// int main(){
//     TreeNode a(1);
//     TreeNode b(2);
//     TreeNode c(3);
//     TreeNode d(4);
//     TreeNode e(5);
//     TreeNode f(6);
//     a.left = &b;
//     a.right = &c;
//     b.left = &d;
//     b.right = &e;
//     c.right = &f;
//     Solution solve;
//     std::vector<int> watch = solve.rightSideView(&a);
//     for(int i = 0; i < watch.size(); i++){
//         std::cout << watch[i];
//     }
//     return 0;
// }

/*------------------Leetcode 187--------------------*/
// 哈希表 重复的DNA序列
// #include<iostream>
// #include<vector>
// #include<map>
// using namespace std;

// class Solution{
// public:
//     vector<string> findRepeatedDnaSequences(string s){
//         //初始化map容器dna，key是string类型，对应长度为10的子串
//         //value是int类型，对应子串的出现次数
//         map<string, int> dna;
//         vector<string> result; //设置字符串数组result,存储满足条件的结果
//         for(int i = 0; i < s.length(); i++){
//             //用substr函数获取从第i个字符起长度为10的子串
//             string word = s.substr(i, 10);
//             if(dna.find(word) != dna.end()){ //重复出现的子串
//                 dna[word] += 1;
//             }
//             else{ //第一次出现的子串
//                 dna[word] = 1;
//             }
//         }
//         map<string, int> :: it; //迭代器遍历dna
//         for(it = dna.begin(); it != dna.end(); it++){
//             if(it->second > 1){ //出现次数大于1的子串，把子串内容存到result结果数组中并返回
//                 result.push_back(it->first);
//             }
//         }
//         return result;
//     }
// };

// int main(){
//     string s = "AAAAAGGGTTCCCCCCAAAAAGGGTTC";
//     Solution solve;
//     vector<string> result = solve.findRepeatedDnaSequences(s);
//     for(int i = 0; i < result.size(); i++){
//         cout << result[i].c_str() << endl;
//     }
//     return 0;
// }

/*------------------Leetcode 198--------------------*/
// dp动态规划Dynamic Programming 房间寻宝 打家劫舍
// #include<iostream>
// #include<vector>
// using namespace std;

// class Solution{
// public:
//     int rob(vector<int>& nums){
//         if(nums.empty()){
//             return 0;
//         }
//         if(nums.size() == 1) return nums[0];
//         vector<int> dp = vector<int>(nums.size(), 0);
//         // dp[0] = nums[0];
//         // dp[1] = max(nums[0], nums[1]);
//         // for(int i = 2; i < nums.size(); i++){
//         //     dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
//         // }
//         // return dp[nums.size() - 1];

//         //滚动数组优化空间复杂度
//         int first = nums[0];
//         int second = max(nums[0], nums[1]);
//         for(int i = 2; i < nums.size(); i++){
//             int temp = second;
//             second = max(first + nums[i], second);
//             first = temp;
//         }
//         return second;
//     }
// };

// int main(){
//     int test[] = {1, 3, 4, 3, 0, 2, 7};
//     vector<int> nums(test, test+7);
//     Solution solve;
//     cout << solve.rob(nums);
//     return 0;
// }

/*------------------Leetcode 322--------------------*/
// dp动态规划 找零钱 零钱兑换
// #include<iostream>
// #include<vector>
// using namespace std;

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         if(amount == 0) return 0;
//         if(amount < 0) return -1;
//         vector<int> dp(amount + 1, amount + 1);
//         dp[0] = 0;
//         for(int i = 1; i < dp.size(); i++){
//             for(int j = 0; j < coins.size(); j++){
//                 dp[i] = min(dp[i], dp[i-coins[j]]+1);
//             }
//         }
//         return dp[amount] > amount ? -1 : dp[amount];
//     }
// };

// int main(){
//     int coin[] = {1, 3, 5};
//     vector<int> coins(coin, coin+3);
//     int amount = 11;
//     Solution solve;
//     cout << solve.coinChange(coins, amount);
//     return 0;
// }


/*---------------------------------------------------------------取自原algorithmnote.cpp文件----------------------------------------------------------------*/
//memset初始化，按字节初始化，速度快，容易出错
/*
#include<iostream>
#include<string.h>
using namespace std;

int main(void)
{
    int a[5]={1,2,3,4,5};
    memset(a,0,sizeof(a));
    for(int i=0;i<5;i++)
    {
        cout<<a[i];
    }
    cout<<endl;
    memset(a,1,sizeof(a));
    for(int j=0;j<5;j++)
    {
        cout<<a[j];
    }
    return 0;
}
*/


/*---------------------------------------第一章 排序算法-----------------------------------------*/
/* 1.1 快速排序算法quickSort.cpp
链接：https://blog.csdn.net/elma_tww/article/details/86164674 */

// #include<iostream>
// using namespace std;
 
// //快速排序算法(从小到大)
// //arr:需要排序的数组，begin:需要排序的区间左边界，end:需要排序的区间的右边界
// void quickSort(int *arr,int begin,int end)
// {
// 	//如果区间不只一个数
// 	if(begin < end)
// 	{
// 		int temp = arr[begin]; //将区间的第一个数作为基准数
// 		int i = begin; //从左到右进行查找时的“指针”，指示当前左位置
// 		int j = end; //从右到左进行查找时的“指针”，指示当前右位置
// 		//不重复遍历
// 		while(i < j)
// 		{
// 			//当右边的数大于基准数时，略过，继续向左查找
// 			//不满足条件时跳出循环，此时的j对应的元素是小于基准元素的
// 			while(i<j && arr[j] > temp)
// 				j--;
// 			//将右边小于等于基准元素的数填入右边相应位置
// 			arr[i] = arr[j];
// 			//当左边的数小于等于基准数时，略过，继续向右查找
// 			//(重复的基准元素集合到左区间)
// 			//不满足条件时跳出循环，此时的i对应的元素是大于等于基准元素的
// 			while(i<j && arr[i] <= temp)
// 				i++;
// 			//将左边大于基准元素的数填入左边相应位置
// 			arr[j] = arr[i];
// 		}
// 		//将基准元素填入相应位置
// 		arr[i] = temp;
// 		//此时的i即为基准元素的位置
// 		//对基准元素的左边子区间进行相似的快速排序
// 		quickSort(arr,begin,i-1);
// 		//对基准元素的右边子区间进行相似的快速排序
// 		quickSort(arr,i+1,end);
// 	}
// 	//如果区间只有一个数，则返回
// 	else
// 		return;
// }
// int main()
// {
// 	int num[12] = {23,45,17,11,13,89,72,26,3,17,11,13};
// 	int n = 12;
// 	quickSort(num,0,n-1);
// 	cout << "排序后的数组为：" << endl;
// 	for(int i=0;i<n;i++)
// 		cout << num[i] << ' ';
// 	cout << endl;
// 	return 0;
// }

/* 1.2 冒泡排序算法bubSort.cpp
最差时间复杂度O(n^2),最优时间复杂度O(n)，平均时间复杂度O(n^2)
链接：http://c.biancheng.net/view/6506.html */

// #include<iostream>
// #include<math.h>
// using namespace std;

// void bubSort(int *arr, int n)
// {
//     while(n > 1)
//     {
//         for(int i = 0; i < n - 1; i++)
//             if(arr[i] > arr[i+1])swap(arr[i], arr[i+1]);
//         n--;
//     }    
// }

// int main()
// {
//     int num[5] = {5,1,4,2,8};
//     int n = sizeof(num)/sizeof(num[0]);
//     // cout << n;
//     bubSort(num, n);
//     cout<< "排序后的数组为：" <<endl;
//     for (int i = 0; i < n; i++)cout<<num[i]<<' ';
//     cout << endl;
//     return 0;
// }

/* 1.3 选择排序算法
链接：https://blog.csdn.net/changhangshi/article/details/82740541 */

// #include<iostream>
// using namespace std;

// void selectSort(int *arr, int n)
// {
//     int time = 0; //已经排好的数量，需要排n-1次
//     int loc = n - 1; //指针标号
//     while(time < n - 1)
//     {
//         for(int i = time; i < n; i++)
//             if(arr[i] < arr[loc]) loc = i;
//         swap(arr[time], arr[loc]);
//         time++;
//     }
// }

// int main()
// {
//     int num[8] = {49,38,65,97,76,13,27,49};
//     int n = sizeof(num)/sizeof(int);
//     selectSort(num, n);
//     cout<< "排序后的数组为：" <<endl;
//     for(int i = 0; i < n; i++)cout<<num[i]<<' ';
//     cout << endl;
//     return 0;
// }

/* 1.4 插入排序算法
1.4.1 直接插入排序法
参考链接：http://c.biancheng.net/view/3439.html */

// #include<iostream>
// using namespace std;

// void insertSort(int *arr, int n)
// {
//     for(int i = 0; i < n; i++)
//     {
//         if(arr[i] < arr[i - 1])
//         {
//             int j = i - 1;
//             int num = arr[i];
//             while (num < arr[j])
//             {
//                 arr[j + 1] = arr[j];
//                 j--;
//             }
//             arr[j + 1] = num;
//         }
//     }
// }

// int main()
// {
//     int num[8] = {3,1,7,5,2,4,9,6};
//     int n = sizeof(num)/sizeof(int);
//     insertSort(num, n);
//     cout<< "排序后的数组为：" <<endl;
//     for(int i = 0; i < n; i++)cout<<num[i]<<' ';
//     cout << endl;
//     return 0;
// }

// 1.4.2 折半插入排序法
// 参考链接：http://c.biancheng.net/view/3440.html

// #include<iostream>
// using namespace std;

// void bInsertSort(int *arr, int n)
// {
//     for(int i = 1; i < n; i++)
//     {
//         int low = 0;
//         int high = i - 1;
//         int num = arr[i];
//         while(low <= high) //这个等于号的范围要千万小心
//         {
//             int mid = ( low + high ) / 2;
//             if(arr[i] < arr[mid])
//                 high = mid - 1;
//             else
//                 low = mid + 1;
//         }
//         //有序表中插入位置后的元素统一后移
//         for(int j = i; j > low; j--)
//             arr[j] = arr[j - 1];
//         arr[low] = num;
//     }
// }

// int main()
// {
//     int num[8] = {3,1,7,5,2,4,9,6};
//     int n = sizeof(num)/sizeof(int);
//     bInsertSort(num, n);
//     cout<< "排序后的数组为：" <<endl;
//     for(int i = 0; i < n; i++)cout<<num[i]<<' ';
//     cout << endl;
//     return 0;
// }

// 1.4.3 2-路插入排序法
// 参考链接：http://c.biancheng.net/view/3441.html
// 难点：环状需要注意越界的问题，通过取余的方法来避免
// 核心：对插入大小在环的什么位置进行分类讨论
// 优点：相比直接插入和折半插入法都大大减少了因为插入值而产生的移动动作

// #include<iostream>
// using namespace std;

// void twoRoadInsert(int arr[], int temp[], int n)
// {
//     //分三类情况讨论
//     int i, first, final, k = 0;
//     temp[0] = arr[0];
//     for(i = 1; i < n; i++)
//     {
//         //当插入值比最小值小
//         if(arr[i] < temp[first])
//         {
//             first = (first - 1 + n) % n;
//             temp[first] = arr[i];
//         }
//         //当插入值比最大值大
//         else if(arr[i] > temp[final])
//         {
//             final = (final + 1 + n) % n;
//             temp[final] = arr[i];
//         }
//         //当插入值介于边界之间
//         else
//         {
//             //首先要解决掉移动位置的问题
//             k = (final + 1 + n) % n;
//             while(arr[i] < temp[(k - 1 + n) % n])
//             {
//                 temp[(k + n) % n] = temp[(k - 1 + n) % n];
//                 k = (k - 1 + n) % n;
//             }
//         temp[(k + n) % n] = arr[i];
//         // 因为最大值的位置改变，所以需要实时更新fianl的位置
//         final = (final + 1 + n) % n;
//         }
//     }
//     for(i = 0; i < n; i++)
//         arr[i] = temp[(first + i) % n]; //（first + i）% n 是相对于最小值的偏移位置
// }

// int main()
// {
//     int num[8] = {3,1,7,5,2,4,9,6};
//     int temp[8] = {0}; //定义数组最好都初始化，否则指针不知道指向哪里会报Segmentation fault的error
//     int n = sizeof(num)/sizeof(int);
//     twoRoadInsert(num, temp, n);
//     cout<< "排序后的数组为：" <<endl;
//     for(int i = 0; i < n; i++)cout<<num[i]<<' ';
//     cout << endl;
//     return 0;
// }

// 1.4.4 表插入排序算法
// 相比直接插入排序法只是避免了移动记录的过程(修改各记录节点中的指针域即可)，
// 而插入过程中同其它关键字的比较次数并没有改变，因此表插入排序算法的时间复杂度仍为O(n^2)
// 参考链接：http://c.biancheng.net/view/3442.html

// #include<iostream>
// using namespace std;

// #define SIZE 20

// // 定义链表节点结构
// typedef struct {
//     int record_content; // 节点内容
//     int next; // 指针项，指向下一个节点
// }SLnode;

// //定义链表结构
// typedef struct {
//     SLnode record[SIZE]; // 存储记录的链表
//     int length; // 记录链表的长度
// }SLinkListType;

// void arrayInsert(SLinkListType *SL)
// {
//     // 在乱序链表的基础上进行重新排列
//     int p = SL->record[0].next; // 临时变量记下一跳的位置
//     for(int i = 1; i < SL->length; i++)
//     {
//         while(p < i) p = SL->record[p].next;
//         int q = SL->record[p].next;
//         if(p != i) // 需要SLnode[p]和SLnode[i]交换
//         {
//             // 临时节点来存储数据
//             SLnode temp;
//             temp = SL->record[p];
//             // 开始交换，注意交换的细节
//             SL->record[p] = SL->record[i];
//             SL->record[i] = temp;
//             SL->record[i].next = p;
//         }
//         p = q;
//     }
// }

// int main()
// {
//     SLinkListType *SL = (SLinkListType*)malloc(sizeof(SLinkListType));
//     SL->length = 6;
//     SL->record[0].record_content = 0;   SL->record[0].next = 4;
//     SL->record[1].record_content = 49;  SL->record[1].next = 3;
//     SL->record[2].record_content = 38;  SL->record[2].next = 1;
//     SL->record[3].record_content = 76;  SL->record[3].next = 0;
//     SL->record[4].record_content = 13;  SL->record[4].next = 5;
//     SL->record[5].record_content = 27;  SL->record[5].next = 2;
//     arrayInsert(SL);
//     for(int i = 0; i < SL->length; i++)
//         cout << SL->record[i].record_content << ' ';
//     cout << endl;
//     return 0;
// }

// 1.4.5 希尔排序算法

// 1.7 堆排序
// 参考链接：http://c.biancheng.net/view/3448.html
// 参考代码
// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 9
// //单个记录的结构体
// typedef struct {
//     int key;
// }SqNote;
// //记录表的结构体
// typedef struct {
//     SqNote r[MAX];
//     int length;
// }SqList;
// //将以 r[s]为根结点的子树构成堆，堆中每个根结点的值都比其孩子结点的值大
// void HeapAdjust(SqList * H,int s,int m){
//     SqNote rc=H->r[s];//先对操作位置上的结点数据进行保存，放置后序移动元素丢失。
//     //对于第 s 个结点，筛选一直到叶子结点结束
//     for (int j=2*s; j<=m; j*=2) {
//         //找到值最大的孩子结点
//         if (j+1<m && (H->r[j].key<H->r[j+1].key)) {
//             j++;
//         }
//         //如果当前结点比最大的孩子结点的值还大，则不需要对此结点进行筛选，直接略过
//         if (!(rc.key<H->r[j].key)) {
//             break;
//         }
//         //如果当前结点的值比孩子结点中最大的值小，则将最大的值移至该结点，由于 rc 记录着该结点的值，所以该结点的值不会丢失
//         H->r[s]=H->r[j];
//         s=j;//s相当于指针的作用，指向其孩子结点，继续进行筛选
//     }
//     H->r[s]=rc;//最终需将rc的值添加到正确的位置
// }
// //交换两个记录的位置
// void swap(SqNote *a,SqNote *b){
//     int key=a->key;
//     a->key=b->key;
//     b->key=key;
// }
// void HeapSort(SqList *H){
//     //构建堆的过程
//     for (int i=H->length/2; i>0; i--) {
//         //对于有孩子结点的根结点进行筛选
//         HeapAdjust(H, i, H->length);
//     }
//     //通过不断地筛选出最大值，同时不断地进行筛选剩余元素
//     for (int i=H->length; i>1; i--) {
//         //交换过程，即为将选出的最大值进行保存大表的最后，同时用最后位置上的元素进行替换，为下一次筛选做准备
//         swap(&(H->r[1]), &(H->r[i]));
//         //进行筛选次最大值的工作
//         HeapAdjust(H, 1, i-1);
//     }
// }

// int main() {
//     SqList * L=(SqList*)malloc(sizeof(SqList));
//     L->length=8;
//     L->r[1].key=49;
//     L->r[2].key=38;
//     L->r[3].key=65;
//     L->r[4].key=97;
//     L->r[5].key=76;
//     L->r[6].key=13;
//     L->r[7].key=27;
//     L->r[8].key=49;
//     HeapSort(L);
//     for (int i=1; i<=L->length; i++) {
//         printf("%d ",L->r[i].key);
//     }
//     return 0;
// }
// 待改代码，主要是下标问题
// #include<iostream>
// using namespace std;

// #define MAX 8

// class SqNote{
//     public:
//         int key;
// };

// class SqList{
//     public:
//         SqNote r[MAX];
//         int length;


// };

// //将以r[s]为根结点的子树构成堆，堆中每个根节点的值都比其孩子结点的值大，即找出子类最大值
// void heapAdjust(SqList* H, int s, int m)
// {
//     SqNote rc = H->r[s];
//     for(int j = 2 * s; j <= m; j *= 2)
//     {
//         if(j + 1 < m && H->r[j].key < H->r[j + 1].key) j++;
//         if(rc.key >= H->r[j].key) break;
//         H->r[s] = H->r[j];
//         s = j;
//     }
//     H->r[s] = rc;
// }

// void heapSort(SqList* H)
// {
//     for(int i = H->length/2 - 1; i > 0; i--)
//         heapAdjust(H, i, H->length); //每个子类都以最大值为根结点
//     for(int i = H->length; i > 1; i--)
//     {
//         swap(H->r[0], H->r[i - 1]);
//         heapAdjust(H, 0, i - 1);
//     }
// }

// int main()
// {
//     SqList* L = (SqList*)malloc(sizeof(SqList));
//     L->length = 8;
//     L->r[0].key = 49;   L->r[1].key = 38;   L->r[2].key = 65;   L->r[3].key = 49;
//     L->r[4].key = 76;   L->r[5].key = 13;   L->r[6].key = 27;   L->r[7].key = 49;
//     heapSort(L);
//     cout << "排序后的数组为：" << endl;
//     for(int i = 0; i < L->length; i++)
//         cout << L->r[i].key << endl;
//     return 0;
// }
/*-----------------------------------第二章 查找算法---------------------------------------*/





// ------------------------------------2021/8/2------------------------------------ //
/*------------------leetcode 刷题模板------------------*/

// #include<iostream>
// #include<vector>
// #include<cstring>
// #include<set>

// using namespace std;

// class Solution
// {
//     public:

// };

// int main(){

//     return 0;
// }

/* 
    动态规划专题
*/
/*------------------数据结构和算法4.5 一、动态规划 576，动态规划解最长公共子串------------------*/
#include<iostream>
#include<vector>
#include<cstring>
#include<set>

using namespace std;

class Solution{
    public:

};

int main(){

    return 0;
}