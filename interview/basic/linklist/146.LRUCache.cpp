#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

// class LRUCache {
// public:
//     // 双向链表结构
//     struct Node {
//         int key, value;
//         Node* pre, *next;
//         Node(int _key, int _value): key(_key), value(_value), pre(NULL), next(NULL) {};
//         ~Node(){delete pre; delete next;}
//     }*head, *end;
//     // 哈希表
//     unordered_map<int, Node*> us;
//     int cap;

//     LRUCache(int capacity) {
//         cap = capacity;
//         head = new Node(-1, -1);
//         end = new Node(-1, -1);
//         head->next = end;
//         end->pre = head;
//     }

//     void remove(Node* p) {
//         p->next->pre = p->pre;
//         p->pre->next = p->next;
//     }

//     void insert(Node* p) {
//         head->next->pre = p;
//         p->next = head->next;
//         head->next = p;
//         p->pre = head;
//     }

//     int get(int key) {
//         if(us.find(key) == us.end()) return -1;
//         auto p = us[key];
//         remove(p);
//         insert(p);
//         return p->value;
//     }

//     void put(int key, int value) {
//         if(us.find(key) != us.end()) {
//             auto p = us[key];
//             p->value = value;
//             remove(p);
//             insert(p);
//         } else {
//             // 从链表尾删除
//             if(us.size() == cap) {
//                 auto p = end->pre;
//                 remove(p);
//                 us.erase(p->key);
//             }
//             Node* np = new Node(key, value);
//             us[key] = np;
//             insert(np);
//         }
//     }
// };

// 迭代器写法，非常优雅的写法
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if(hash.find(key) == hash.end()) return -1;
        auto kv = *hash[key];
        // 擦除
        cache.erase(hash[key]);
        // 头插并更新哈希表
        cache.push_front(kv);
        hash[key] = cache.begin();
        return kv.second;
    }
    
    void put(int key, int value) {
        if(hash.find(key) == hash.end()) {
            // 清理一个缓存位置出来
            if(cache.size() == cap) {
                hash.erase(cache.back().first);
                cache.pop_back();
            }
        } else {
            cache.erase(hash[key]);
        }
        cache.push_front(make_pair(key, value));
        hash[key] = cache.begin();
    }
private:
    int cap;
    list<pair<int, int> > cache;
    unordered_map<int, list<pair<int, int> >::iterator> hash;
};

int main() {
    LRUCache* lru = new LRUCache(2);
    lru->put(1, 1);
    lru->put(2, 2);
    cout << lru->get(1);
    lru->put(3, 3);
    cout << lru->get(2);
    lru->put(4, 4);
    cout << lru->get(1);
    cout << lru->get(3);
    cout << lru->get(4);
    return 0;
}