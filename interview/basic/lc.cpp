#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void show_tree(TreeNode* root) {
    cout << root->data << " ";
    if(root->left) show_tree(root->left);
    if(root->right) show_tree(root->right);
}

vector<int> showRightView(TreeNode* root) {
    if(!root) return vector<int>();
    vector<int> ans;
    queue<pair<TreeNode*, int> > q;
    q.push(make_pair(root, 0));
    while(!q.empty()) {
        TreeNode* curr = q.front().first;
        int currLevel = q.front().second;
        q.pop();
        if(ans.size() <= currLevel) {
            ans.push_back(0);
        }
        ans[currLevel] = curr->data;
        if(curr->left)
            q.push(make_pair(curr->left, currLevel+1));
        if(curr->right)
            q.push(make_pair(curr->right, currLevel+1));
    }
    return ans;
}

int main() {
    // 建树
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    show_tree(node1);
    vector<int> res;
    res = showRightView(node1);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}