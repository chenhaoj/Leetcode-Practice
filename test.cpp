#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<limits>
#include<unordered_map>
using namespace std;

// struct Node {
//     char data;
//     Node *lchild, *rchild;
//     Node(): data(), lchild(NULL), rchild(NULL){}
//     Node(char ch): data(ch), lchild(NULL), rchild(NULL){}
// };

/* // 1.重载"<"运算符（写在类外部）
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
}; */

// typedef struct {
//     int x;
//     int y;
//     // Node(): x(0), y(0){}
//     // Node(int _x, int _y):x(_x), y(_y){}
// }Node;

struct Node {
    int x;
    int y;
};

// bool cmp(vector<int>& a, vector<int>& b) {
//     if(a[0] == b[0])
//         return a[1] < b[1];
//     else
//         return a[0] < b[0];
// }

// struct cmp {
//     bool operator()(vector<int>& a, vector<int>& b) const {
//         if(a[0] == b[0])
//             return a[1] < b[1];
//         else
//             return a[0] < b[0];
//     }
// };

struct cmp {
    bool operator()(Node& a, Node& b) {
        if(a.x == b.y) return a.x < b.x;
        else return a.y < b.y;
    }
};

// bool cmp(Node& a, Node& b) {
//     if(a.x == b.x) return a.y < b.y;
//     else return a.x < b.x;
// }

int main() {
    // int n;
    // cin >> n;
    // vector<vector<int> > sum(2, vector<int>(n, 0));
    // for(int i = 0; i < 2; i++) {
    //     for(int j = 0; j < n; j++) {
    //         int currNum = 0;
    //         cin >> currNum;
    //         if(j >= 1) sum[i][j] += sum[i][j-1] + currNum;
    //         else sum[i][j] = currNum;
    //     }
    // }
    
    // int ans = 0;
    // vector<int> dp(n);
    // for(int i = 0; i < n; i++) {
    //     ans = max(sum[1][i], sum[0][n-1]-sum[0][i]);
    // }
    // cout << ans << endl;
    // return 0;
    int n;
    cin >> n;
    // vector<vector<int> > nums(n, vector<int>(2, 0));
    // for(int i = 0; i < n; i++) {
    //     cin >> nums[i][0] >> nums[i][1];
    // }
    // sort(nums.begin(), nums.end(), cmp());
    // for(int i = 0; i < n; i++) {
    //     cout << nums[i][0] << nums[i][1] << endl;
    // }

    vector<Node> nodes(n);
    for(int i = 0; i < n; i++) {
        int temp_x, temp_y;
        cin >> temp_x >> temp_y;
        // Node* temp_node = new Node(temp_x, temp_y);
        // nodes[i] = *temp_node;
        Node node = {x:temp_x, y:temp_y};
        nodes[i] = node;
    }
    sort(nodes.begin(), nodes.end(), cmp());
    for(int i = 0; i < n; i++) {
        cout << nodes[i].x << nodes[i].y << endl;
    }
    return 0;
}