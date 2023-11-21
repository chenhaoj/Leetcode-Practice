#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* lchild;
    Node* rchild;
    Node(): data(0), lchild(NULL), rchild(NULL){}
    Node(int v): data(v), lchild(NULL), rchild(NULL){}
};

bool search(Node* root, int target) {
    if(root == nullptr) return false;
    if(root->data == target) {
        return true;
    }
    bool left = search(root->lchild, target);
    bool right = search(root->rchild, target);
    return left || right;
}

// void insert(Node*& root, int num) { // 注意这里是指针root的引用&，该insert建一棵二叉查找树
//     if(num == -1) return;
//     if(root == nullptr) {
//         root = new Node(num);
//         return;
//     }
//     if(root->data > num) insert(root->lchild, num);
//     else insert(root->rchild, num); 
// }

int str2int(string str) {
    if(str == "") return 0;
    int num = 0;
    for(int i = 0; i < str.length(); i++) {
        num *= 10;
        num += str[i] - '0';
    }
    return num;
}

Node* create(vector<string> nums) {
    // 用队列层序建树
    queue<Node*> nodeQueue;
    int n = nums.size();
    Node* root = new Node(str2int(nums[0]));
    nodeQueue.push(root);
    int idx = 1;
    while(!nodeQueue.empty()) {
        // int size= nodeQueue.size();
        Node* currRoot = nodeQueue.front();
        nodeQueue.pop();
        // 插入左子树
        if(idx < n) {
            if(nums[idx] == "null") {
                currRoot->lchild = NULL;
            } else {
                // int num_ = str2int(nums[idx]);
                Node* lchild = new Node(str2int(nums[idx]));
                currRoot->lchild = lchild;
                nodeQueue.push(currRoot->lchild);
            }
            idx++;
        }
        // 插入右子树
        if(idx < n) {
            if(nums[idx] == "null") {
                currRoot->rchild = NULL;
            } else {
                // int num_ = str2int(nums[idx]);
                Node* rchild = new Node(str2int(nums[idx]));
                currRoot->rchild = rchild;
                nodeQueue.push(currRoot->rchild);
            }
            idx++;
        }
    }
    return root;
}

void preorder(Node* root) {
    if(root == NULL) {
        cout << "null" << " ";
        return;
    }
    cout << root->data << " ";
    preorder(root->lchild);
    preorder(root->rchild);
    return;
}

void inorder(Node* root) {
    if(root == NULL) {
        cout << "null" << " ";
        return;
    }
    inorder(root->lchild);
    cout << root->data << " ";
    inorder(root->rchild);
    return;
}

void postorder(Node* root) {
    if(root == NULL) {
        cout << "null" << " ";
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    cout << root->data << " ";
    return;
}


void layorder(Node* root) {
    queue<Node*> q;
    q.push(root);
    // int idx = 1;
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            if(node->data == -1) cout << "null" << " ";
            else {
                cout << node->data << " ";
                if(node->lchild) q.push(node->lchild);
                else if(node->lchild == nullptr) {
                    Node* tempNode = new Node(-1);
                    q.push(tempNode);
                }
                if(node->rchild) q.push(node->rchild);
                else if(node->rchild == nullptr) {
                    Node* tempNode = new Node(-1);
                    q.push(tempNode);
                }
            }
        }
    }
    return;
}

Node* findMax(Node* root) {
    while(root->rchild != NULL) {
        root = root->rchild;
    }
    return root;
}

Node* findMin(Node* root) {
    while(root->lchild != NULL) {
        root = root->lchild;
    }
    return root;
}

// 二叉排序树的节点删除
void deleteNode(Node* root, int target) {
    if(root == NULL) return;
    if(root->data == target) {
        if(root->lchild == NULL && root->rchild == NULL) {
            root = NULL;
        } else if(root->lchild != NULL) {
            Node* leftMax = findMax(root->lchild);
            root->data = leftMax->data;
            deleteNode(root->lchild, leftMax->data);
        } else {
            Node* rightMin = findMin(root->rchild);
            root->data = rightMin->data;
            deleteNode(root->rchild, rightMin->data);
        }
    } else if(root->data < target) {
        deleteNode(root->rchild, target);
    } else {
        deleteNode(root->lchild, target);
    }
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<string> nums(n, "");
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Node* root = create(nums);
    // cout << root->data << endl;
    layorder(root);
    cout << endl;
    // // search(root, x, 0);
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    layorder(root);
    cout << endl;
    return 0;
}