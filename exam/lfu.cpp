#include <unordered_map>
#include <set>

using namespace std;

struct Node {
    int cnt, time;
    int key, val;
    Node(int c, int t, int k, int v) : cnt(c), time(t), key(k), val(v) {}
};

// bool nodePtrLess(Node* lhs, Node* rhs) {
//     if (lhs->cnt == rhs->cnt)
//         return lhs->time < rhs->time;
//     return lhs->cnt < rhs->cnt;
// }

class LFUCache {
    static bool nodePtrLess(Node* lhs, Node* rhs) {
        if (lhs->cnt == rhs->cnt)
            return lhs->time < rhs->time;
        return lhs->cnt < rhs->cnt;
    }

    unordered_map<int, Node*> umap;
    set<Node*, decltype(&nodePtrLess)> tree;
    int time;
    int capacity;  
public:
    LFUCache(int capa) : time(0), capacity(capa){
        umap.clear();
        tree.clear();
    }
    
    int get(int key) {
        if (capacity == 0)
            return -1;
        auto it = umap.find(key);
        if (it == umap.end())
            return -1;
        Node *tmp = it->second;
        tree.erase(tmp);
        tmp->cnt++;
        tmp->time = ++time;
        tree.insert(tmp);
        return tmp->val;
    }
    
    void put(int key, int value) {
        if (capacity == 0)
            return;
        auto it = umap.find(key);
        if (it == umap.end()) {
            if (umap.size() == capacity) {
                Node *tmp = *tree.begin();
                umap.erase(tmp->key);
                tree.erase(tree.begin());
                delete tmp;
            }
            Node *tmp = new Node(1, ++time, key, value);
            umap[key] = tmp;
            tree.insert(tmp);
        }
        else {
            Node *tmp = it->second;
            tree.erase(tmp);
            tmp->cnt++;
            tmp->time = ++time;
            tree.insert(tmp);
        }
    }
};

int main()
{
    LFUCache lfu = LFUCache(2);
    lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    lfu.get(1);      // 返回 1
                    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
                    // cache=[3,1], cnt(3)=1, cnt(1)=2
    lfu.get(2);      // 返回 -1（未找到）
    lfu.get(3);      // 返回 3
                    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
                    // cache=[4,3], cnt(4)=1, cnt(3)=2
    lfu.get(1);      // 返回 -1（未找到）
    lfu.get(3);      // 返回 3
                    // cache=[3,4], cnt(4)=1, cnt(3)=3
    lfu.get(4);
}