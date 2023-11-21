#include<iostream>
using namespace std;

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回节点权值1个数比0的个数多一的路径数
     * @param root TreeNode类 权值为0和1的二叉树根节点
     * @return int整型
     */
    int ans = 0;
    void dfs(TreeNode* node, int jishu, int oushu) {
        if(node->val % 2 == 0) oushu++;
        else jishu++;
        if(node->left == nullptr && node->right == nullptr) {
            if(jishu - oushu == 1) ans++;
            return;
        };
        if(node->left) dfs(node->left, jishu, oushu);
        if(node->right) dfs(node->right, jishu, oushu);
    }
    int pathNumber(TreeNode* root) {
        if(root == nullptr) return 0;
        int jishu = 0, oushu = 0;
        dfs(root, jishu, oushu);
        return ans;
    }
};