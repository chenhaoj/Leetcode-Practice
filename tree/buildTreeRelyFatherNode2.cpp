#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#include <unordered_map>
using namespace std;

struct Node {
    char data;
    Node *lchild, *rchild;
    Node(): data(), lchild(NULL), rchild(NULL){}
    Node(char ch): data(ch), lchild(NULL), rchild(NULL){}
};

// Node* find(Node* root, char ch) {
//     if(root == NULL) return;
//     else {
//         if(root->data = )
//     }
// }

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
            // if(currRoot == NULL) cout << "# ";
            // else cout << currRoot->data << " ";
            cout << currRoot->data << " ";
            nodeQueue.pop();
            if(currRoot->lchild) nodeQueue.push(currRoot->lchild);
            if(currRoot->rchild) nodeQueue.push(currRoot->rchild);
        }
    }
}

unordered_map<char, char> parents;
unordered_map<char, Node*> ch_to_node;
Node* buildBiTree(vector<char> nodes) {
    int size = nodes.size();
    if(size == 0) return nullptr;
    else {
        for(int i = 0; i < size; i++) {
            if(ch_to_node.find(parents[nodes[i]]) != ch_to_node.end()) {
                // 创建节点
                Node* newparent = new Node(parents[nodes[i]]);
                ch_to_node.insert(make_pair(parents[nodes[i]], newparent));
                Node* newnode = new Node(nodes[i]);
                ch_to_node.insert(make_pair(nodes[i], newnode));
                newparent->lchild = newnode;
            } else {
                // 直接连接
                Node* newnode = new Node(nodes[i]);
                Node* parentnode = ch_to_node[parents[nodes[i]]];
                parentnode->rchild = newnode;
                ch_to_node.insert(make_pair(nodes[i], newnode));
            }
        }
    }
    return ch_to_node[nodes[0]];
}

int main() {
    int n;
    cin >> n;
    vector<char> nodes(n);
    char node_data, node_parent;
    for(int i = 0; i < n; i++) {
        cin >> node_data >> node_parent;
        nodes.push_back(node_data);
        parents.insert(make_pair(node_data, node_parent));
    }
    // 根据父节点关系建树
    Node* root = buildBiTree(nodes);
    // vector<Node*> parentNodes;
    // Node* root = new Node(nodes[0]);
    // parentNodes.push_back(root);
    // for(int i = 0; 2*i+1 < size; i++) {
    //     // cout << i << ":  ";
    //     Node* currRoot = parentNodes[i];
    //     // 先看左孩子
    //     Node* lchild;
    //     if(2*i+1 < size) {
    //         if(nodes[2*i+1] != '#') {
    //             lchild = new Node(nodes[2*i+1]);
    //         } else {
    //             lchild = NULL;
    //         }
    //         currRoot->lchild = lchild;
    //         parentNodes.push_back(lchild);
    //     }
    //     // 再看右孩子
    //     Node* rchild;
    //     if(2*i+2 < size) {
    //         if(nodes[2*i+2] != '#') {
    //             rchild = new Node(nodes[2*i+2]);
    //         } else {
    //             rchild = NULL;
    //         }
    //         currRoot->rchild = rchild;
    //         parentNodes.push_back(rchild);
    //     }
    // }
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