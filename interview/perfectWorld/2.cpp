#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main() {
    vector<int> vec;
    int num;
    while(cin >> num) {
        vec.push_back(num);
        if(getchar() == '\n')
            break;
    }
    int x = vec[vec.size()-1];
    ListNode* pHead = new ListNode(vec[0]);
    ListNode* p = pHead;
    for(int i = 1; i < vec.size()-1; i++) {
        ListNode* tempNode = new ListNode(vec[i]);
        p->next = tempNode;
        p = p->next;
    }
    ListNode* smallList = new ListNode(-1);
    ListNode* bigList = new ListNode(-1);
    ListNode* ps = smallList, *pb = bigList, *cur = pHead;
    while (cur) {
        if (cur->val < x) {
            ps->next = cur;
            ps = cur;
        }
        else {
            pb->next = cur;
            pb = cur;
        }
        cur = cur->next;
    }
    pb->next = nullptr;
    ps->next = bigList->next;
    smallList = smallList->next;
    while(smallList) {
        cout << smallList->val << "->";
        smallList = smallList->next;
    }
    return 0;
}

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
  public:
    ListNode* partition(ListNode* pHead, int x) {
        if (pHead == nullptr) {
            return nullptr;
        }
        ListNode* smallList = new ListNode(-1);
        ListNode* bigList = new ListNode(-1);
        ListNode* ps = smallList, *pb = bigList, *cur = pHead;
        while (cur) {
            if (cur->val < x) {
                ps->next = cur;
                ps = cur;
            }
            else {
                pb->next = cur;
                pb = cur;
            }
            cur = cur->next;
        }
        pb->next = nullptr;
        ps->next = bigList->next;
        return smallList->next;
    }
};