#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

vector<char> parent;
struct Node {
    char data;
    Node *lchild, *rchild;
    Node(): data(), lchild(NULL), rchild(NULL){}
    Node(char ch): data(ch), lchild(NULL), rchild(NULL){}
};
/* 先序遍历二叉树 */
void PreorderTraverse(Node* root) {
    if(root == NULL) {
        cout << "# ";
        return;
    } else {
        cout << root->data << " ";
        PreorderTraverse(root->lchild);
        PreorderTraverse(root->rchild);
    }
}
/* 中序遍历二叉树 */
void InorderTraverse(Node* root) {
    if(root == NULL) {
        cout << "# ";
        return;
    } else {
        InorderTraverse(root->lchild);
        cout << root->data << " ";
        InorderTraverse(root->rchild);
    }
}
/* 后序遍历二叉树 */
void PostorderTraverse(Node* root) {
    if(root == NULL) {
        cout << "# ";
        return;
    } else {
        PostorderTraverse(root->lchild);
        PostorderTraverse(root->rchild);
        cout << root->data << " ";
    }
}
/* 层序遍历二叉树 */
void LayerTraverse(Node* root) {
    if(root == NULL) return;
    else {
        queue<Node*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()) {
            Node* currRoot = nodeQueue.front();
            cout << currRoot->data << " ";
            nodeQueue.pop();
            if(currRoot->lchild) nodeQueue.push(currRoot->lchild);
            if(currRoot->rchild) nodeQueue.push(currRoot->rchild);
        }
    }
}

int main() {
    vector<char> nodes;
    char node_data;
    while(cin >> node_data) {
        nodes.push_back(node_data);
        if(cin.get() == '\n') break;
    }
    int size = nodes.size();
    parent.resize(size);
    /* 计算父节点的时候有两种下标法: 
    1、从0开始，则父节点为(i+1)/2-1;
    2、从1开始，则父节点为(i+2)/2-1;
     */
    // 下标从0开始
    /* parent[0] = 0;
    for(int i = 1; i < size; i++) {
        parent[i] = (i+1)/2-1;
    } */
    // 根据父节点关系建树
    vector<Node*> parentNodes;
    Node* root = new Node(nodes[0]);
    parentNodes.push_back(root);
    for(int i = 0; 2*i+1 < size; i++) {
        // cout << i << ":  ";
        Node* currRoot = parentNodes[i];
        // if(currRoot == NULL) continue;
        // 先看左孩子
        Node* lchild;
        if(2*i+1 < size) {
            // cout << "insert: " << 2*i+1 << endl;
            if(nodes[2*i+1] != '#') {
                lchild = new Node(nodes[2*i+1]);
            } else {
                lchild = NULL;
            }
            currRoot->lchild = lchild;
            parentNodes.push_back(lchild);
        }
        // 再看右孩子
        Node* rchild;
        if(2*i+2 < size) {
            // cout << "insert: " << 2*i+2 << endl;
            if(nodes[2*i+2] != '#') {
                rchild = new Node(nodes[2*i+2]);
            } else {
                rchild = NULL;
            }
            currRoot->rchild = rchild;
            parentNodes.push_back(rchild);
        }
        // cout << endl;
    }
    cout << "中序遍历输出：";
    InorderTraverse(root);
    cout << endl << "先序遍历输出:";
    PreorderTraverse(root);
    cout << "\n" << "后序遍历输出:";
    PostorderTraverse(root);
    cout << "\n" << "层序遍历输出:";
    LayerTraverse(root);
    cout << endl;
    return 0;
}