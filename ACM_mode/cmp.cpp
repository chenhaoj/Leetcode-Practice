#include <iostream>
#include <queue>
using namespace std;

struct Edge {
    int len, x, y;
    Edge(int _len, int _x, int _y) : len(_len), x(_x), y(_y) {}
};

class Node {
private:
	int x_, y_;

public:
	Node(int x = 0, int y = 0) :x_(x), y_(y) {}

	// 1.重载"<"运算符（写在类内部）
	bool operator<(const Node& a)const { // 注意这里的两个const，第一个const表示node_a必须为const;第二个const表示只可以被const的node调用
        // 返回true，表示this的优先级小于a
		// x大的排在前面；x相同时，y大的排在前面
		if (x_ == a.x_) return y_ > a.y_;
		return x_ > a.x_;
	}

	// 2.重写仿函数（写在类内部）STL中的greater()和less()都是仿函数，这里相当于自己重写一个仿函数来代替它们
	bool operator()(Node& a, Node& b) const { // 返回true，表示this的优先级小于a
	// x大的排在前面；x相同时，y大的排在前面
		if (a.get_x() == b.get_x()) return a.get_y() > b.get_y();
		return a.get_x() > b.get_x();
	}

	// 获取x_和y_的值
	int get_x() { return x_; };
	int get_y() { return y_; };

	// 打印函数
	void print() const {
		cout << x_ << " " << y_ << endl;
	}
};

// 1.重载"<"运算符（写在类外部）
bool operator<(Node& a, Node& b) { // 返回true，表示this的优先级小于a
	// x大的排在前面；x相同时，y大的排在前面
	if (a.get_x() == b.get_x()) return a.get_y() > b.get_y();
	return a.get_x() > b.get_x();
}

// 2.重写仿函数（写在类外部）
struct cmp {
	bool operator()(Node& a, Node& b) const { // 返回true，表示this的优先级小于a
	// x大的排在前面；x相同时，y大的排在前面
		if (a.get_x() == b.get_x()) return a.get_y() > b.get_y();
		return a.get_x() > b.get_x();
	}
};

// 3.函数指针：通过编写一个外部的比较函数，实现<方法，然后将函数指针传入
bool cmp1(Node& a, Node& b) { // 返回true，表示this的优先级小于a
	// x大的排在前面；x相同时，y大的排在前面
	if (a.get_x() == b.get_x()) return a.get_y() > b.get_y();
	return a.get_x() > b.get_x();
}

// 4.lambda表达式
// auto cmp2 = [](Node& a, Node& b) {return a.get_x() == b.get_x() ? a.get_y() > b.get_y() :a.get_x() > b.get_x(); };
auto cmp2 = [](Node& a, Node& b) {return a.get_x() == b.get_x() ? a.get_y() > b.get_y() : a.get_x() > b.get_x();};

int main() {
	/* 常规环境：待排序数组 */
	// vector<Node> vec{ Node(10,20),Node(20,10),Node(10,10) };

	// // 使用不同的自定义比较函数进行排序
	// int mode = 3;
	// switch (mode) {
    //     case 1:sort(vec.begin(), vec.end());		 // 1.重载"<"运算符
    //     case 2:sort(vec.begin(), vec.end(), Node()); // 2.重写仿函数（类内实现）
    //     case 3:sort(vec.begin(), vec.end(), cmp());  // 3.重写仿函数（类外实现）
    //     case 4:sort(vec.begin(), vec.end(), cmp1);   // 4.函数指针
    //     case 5:sort(vec.begin(), vec.end(), cmp2);   // 5.lambda表达式
	// }
	
	// // 打印排序结果
	// for (auto node : vec) node.print();

    /* 容器环境：priority_queue、map、set */
    // priority_queue<Node> pq; // 1.重载"<"运算符
    // priority_queue<Node, vector<Node>, Node> pq; // 2.重写仿函数（类内实现）
    // priority_queue<Node, vector<Node>, cmp> pq; // 3.重写仿函数（类外实现）
    // priority_queue<Node, vector<Node>, function<bool(Node& a, Node&b)> > pq(cmp1); // 4.函数指针
    // priority_queue<Node, vector<Node>, decltype(cmp2)> pq(cmp2); // 5.lambda表达式
    // pq.push(Node(10,20));
    // pq.push(Node(20,10));
    // pq.push(Node(10,10));

    // while(!pq.empty()) {
    //     pq.top().print();
    //     pq.pop();
    // }

    /* Edge测试 */
    vector<Edge> edges;
    edges.push_back(Edge(2, 1, 3));
    edges.push_back(Edge(1, 0, 1));
    // sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
    //     return a.len < b.len;
    // });
    // sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) -> bool {return a.len < b.len;});

    cout << edges[0].len << endl;

	// priority_queue<Node, vector<Node>, decltype(cmp2)> q(cmp2);
	// q.push(Node(1,2));
	// q.push(Node(1,3));
	// q.push(Node(2,3));
	// cout << q.top()->get_x << q.top()->get_y << endl;
	
    return 0;
}
