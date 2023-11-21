/* 
算法：
1) 写一个循环双向链表类，提供插入头和插入尾的方法
2) 现有一个上面的链表，其中元素已排好序，写一个方法，插入新元素到这个链表
 */

#include<iostream>
#include<vector>
using namespace std;

// class Node {
// public:
//     int val;
//     Node* prev;
//     Node* next;
//     Node(int _val) {
//         val = _val;
//         prev = NULL;
//         next = NULL;
//     }
// };

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int _val): val(_val), prev(NULL), next(NULL){}
};

class MyList {
public:
    Node* head;
    Node* end;
    MyList() {
        head = new Node(0);
        end = new Node(0);
        head->next = end;
        end->prev = head;
    };
    
    void insertFront(int _val) {
        Node* newNode = new Node(_val);
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }

    void insertEnd(int _val) {
        Node* newNode = new Node(_val);
        newNode->prev = end->prev;
        end->prev->next = newNode;
        end->prev = newNode;
        newNode->next = end;
    }

    void insertNode(int _val) {
        Node* newNode = new Node(_val);
        Node* p = head->next;
        if(_val >= end->prev->val) insertEnd(_val);
        else if(_val < head->next->val) insertFront(_val);
        else {
            while(p) {
                if(p->next && p->next->val > _val) {
                    p->next->prev = newNode;
                    newNode->next = p->next;
                    newNode->prev = p;
                    p->next = newNode;
                    break;
                }
                p = p->next;
            }
        }
    }

    void show() {
        Node* p = head;
        while(p->next && p->next != end) {
            p = p->next;
            cout << p->val << "->";
        }
        cout << endl;
    }
};

int main() {
    MyList* ls = new MyList();
    ls->insertFront(2);
    ls->insertFront(1);
    ls->insertEnd(4);
    ls->insertEnd(5);
    ls->show();
    ls->insertNode(0);
    ls->insertNode(3);
    ls->insertNode(6);
    ls->show();
    return 0;
}