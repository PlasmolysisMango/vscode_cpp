#include <iostream>
#include <unordered_map>
using namespace std;

struct DListNode {
    int key, val;
    DListNode *next, *prev;
    DListNode(): key(0), val(0), next(nullptr), prev(nullptr) {}
    DListNode(int k, int v): key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    unordered_map<int, DListNode*> umap;
    int capacity;
    int size;
    DListNode *dhead, *dtail;

    void addToHead(DListNode *node)
    {
        node->next = dhead->next;
        dhead->next->prev = node;
        node->prev = dhead;
        dhead->next = node;
    }

    void removeNode(DListNode *node)
    {
        if (node == dhead || node == dtail)
            return;
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capa): capacity(capa), size(0) {
        dhead = new DListNode();
        dtail = new DListNode();
        dhead->next = dtail;
        dtail->prev = dhead;
    }
    
    int get(int key) {
        auto it = umap.find(key);
        if (it == umap.end())
            return -1;
        DListNode *recent = (*it).second;
        removeNode(recent);
        addToHead(recent);
        return recent->val;
    }
    
    void put(int key, int value) {
        auto it = umap.find(key);
        if (it != umap.end()) {
            DListNode *recent = (*it).second;
            recent->val = value;
            removeNode(recent);
            addToHead(recent);
        }
        else {
            DListNode *recent = new DListNode(key, value);
            umap[key] = recent;
            addToHead(recent);
            ++size;
            if (size > capacity) {
                DListNode *tmp = dtail->prev;
                removeNode(tmp);
                umap.erase(tmp->key);
                delete tmp;
                --size;
            }
        }
    }
};

int main() 
{
    LRUCache lRUCache = LRUCache(2);
    lRUCache.put(1, 0); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    auto x = lRUCache.get(1);    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    auto y = lRUCache.get(2);    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lRUCache.get(1);    // 返回 -1 (未找到)
    lRUCache.get(3);    // 返回 3
    lRUCache.get(4);    // 返回 4
}