#include <iostream>
#include <vector>
using namespace std;

/*定义二叉树的结构*/
struct Node {
    char data;
    Node *lchild, *rchild;
};

/* 只靠先序是不是创建的树不唯一？？？ */
/* 先序创建二叉树 */
void CreateBiTree(Node*& T) {
    char ch;
    cin >> ch;
    if(ch == '#') {
        T = NULL;
    } else {
        T = new Node;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

void PreorderTraverse(Node* T) {
    if(T == NULL) {
        return;
    } else {
        cout << T->data << " ";
        PreorderTraverse(T->lchild);
        PreorderTraverse(T->rchild);
    }
}

void InorderTraverse(Node* T) {
    if(T == NULL) {
        return;
    } else {
        InorderTraverse(T->lchild);
        cout << T->data << " ";
        InorderTraverse(T->rchild);
    }
}

void PostorderTraverse(Node* T) {
    if(T == NULL) {
        return;
    } else {
        PostorderTraverse(T->lchild);
        PostorderTraverse(T->rchild);
        cout << T->data << " ";
    }
}

/*统计二叉树中结点的个数*/
int NodeCount(Node* T) {
    if(T == NULL) return 0;
    else return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}

/*求树的深度*/
int Depth(Node* T) {
    if(T == NULL) return 0;
    else {
        int leftDepth = Depth(T->lchild);
        int rightDepth = Depth(T->rchild);
        return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
    }
}

int main() {
    Node* root;
    //测试数据AB#CD##E##F#GH###
    cout << "先序遍历输入(以#结束)：";
    CreateBiTree(root);
    cout << "中序遍历输出：";
    InorderTraverse(root);
    cout << endl << "先序遍历输出:";
    PreorderTraverse(root);
    cout << "\n" << "后序遍历输出:";
    PostorderTraverse(root);
    cout << endl << "树的深度:" << Depth(root);
    cout << endl << "结点的个数:" << NodeCount(root);
    return 0;
}