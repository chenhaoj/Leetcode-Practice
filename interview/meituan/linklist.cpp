#include<iostream>
#include<stack>
using namespace std;

struct LinkList {
    int value;
    LinkList* next;
};

int main() {
    LinkList *head = new LinkList();
    head->value = 1;
    LinkList *p = head;
    LinkList *node1 = new LinkList();
    node1->value = 2;
    LinkList *node2 = new LinkList();
    node2->value = 3;
    LinkList *node3 = new LinkList();
    node3->value = 4;
    LinkList *node4 = new LinkList();
    node4->value = 5;
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    p = head;
    int len = 0;
    while(p) {
        len++;
        p = p->next;
    }
    int mid = len/2;
    p = head;
    stack<LinkList*> st;
    while(p) {
        if(mid <= 0) {
            st.push(p);
        }
        p = p->next;
        mid--;
    }
    // while(!st.empty()) {
    //     cout << st.top()->value << endl;
    //     st.pop();
    // }
    p = head;
    // while(p) {
    //     if(!st.empty()) {
    //         st.top()->next = nullptr;
    //         LinkList* node = st.top();
    //         st.pop();
    //         // cout << node->value << endl;
    //         node->next = p->next;
    //         p->next = node;
    //         p = p->next->next;
    //     }
    // }
    while(!st.empty()){
        LinkList* node = st.top();
        st.pop();
        node->next = p->next;
        p->next = node;
        p = p->next->next;
    }
    p = head;
    while(len > 0) {
        len--;
        p = p->next;
    }
    p->next = nullptr;
    p = head;
    while(p) {
        cout << p->value << endl;
        p = p->next;
    }
    
    return 0;
}