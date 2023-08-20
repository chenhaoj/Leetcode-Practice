#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val): data(val), next(NULL){}
};

void show_list(ListNode* head) {
    while(head != nullptr) {
        cout << head->data <<"->";
        head = head->next;
    }
}

ListNode* iterationReverseList(ListNode* head) {
    if(!head) return nullptr;
    ListNode* prev = nullptr;
    ListNode* temp = head;
    while(temp) {
        ListNode* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

ListNode* recursionReverseList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode* newhead = recursionReverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newhead;
}

ListNode* stackReverseList(ListNode* head) {
    if(!head) return nullptr;
    stack<ListNode*> st;
    while(head->next) {
        st.push(head);
        head = head->next;
    }
    ListNode* pt = head;
    while(!st.empty()) {
        ListNode* curr = st.top();
        st.pop();
        pt->next = curr;
        pt = pt->next;
    }
    pt->next = nullptr;
    return head;
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    show_list(node1);
    // ListNode* newList = iterationReverseList(node1);
    // show_list(newList);
    // ListNode* newList2 = recursionReverseList(node1);
    // show_list(newList2);
    ListNode* newList3 = stackReverseList(node1);
    show_list(newList3);
    return 0;
}