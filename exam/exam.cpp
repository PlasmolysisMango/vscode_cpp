#include <queue>
#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <memory>
#include <functional>
#include <cstring>   
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;









const int N = 1e5 + 10, M = N * 2;
struct Edge {
    int to; 	//子节点
    int w;		//权重
    int next;	//每个head链表的下一个节点
} edge[M * 2];  //M表示边的数目，两倍是针对无向边
 
int head[N], idx = 0; //N表示点的数目
 
void add_edge(int from, int to, int w)
{
    edge[idx].to = to;
    edge[idx].w = w;
    edge[idx].next = head[from];
    head[from] = idx++;
}
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
};

struct NTreeNode {
    int val;
    vector<NTreeNode *> children;
    NTreeNode(): val(0), children({}) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
};

bool visited[N];
void dfs(int u)
{
    visited[u] = true;
    for (int i = head[u]; ~i; i = edge[i].next) // i != -1;
    {
        int son = edge[i].to;
        if (!visited[son]) 
            dfs(son);
    }
}

int q[N];
bool visited[N];
void bfs(int u)
{
    int hh = 0, tt = 0;
    q[0] = u;
    visited[u] = true;
    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = head[t]; ~i; i = edge[i].next)
        {
            int son = edge[i].to;
            if (!visited[son])
            {
                q[++tt] = son;
                visited[son] = true;
            }
        }
    }
}

vector<int> getNextVec(const string &s)
{
    vector<int> next(s.size(), 0);
    int j = -1;
    next[0] = j;
    for (int i = 1; i < s.size(); ++i) {
        while (j >= 0 && s[i] != s[j+1])
            j = next[j];
        if (s[i] == s[j+1])
            j++;
        next[i] = j;
    }
    return next;
}

int strStr(string haystack, string needle) {
    // aabaaf aaf (-1 0 -1)
    if (!needle.size())
        return 0;
    auto next = getNextVec(needle);
    int j = -1;
    for (int i = 0; i < haystack.size(); ++i) {
        while (j >= 0 && haystack[i] != needle[j+1])
            j = next[j];
        if (haystack[i] == needle[j+1])
            ++j;
        if (j == needle.size() - 1)
            return i - j;
    }
    return -1;
}

int main() {
    vector<int> ivec{0, 1, 2, 1, 4, 4};
    vector<TreeNode> tree(6, TreeNode());
    TreeNode *root = nullptr;
    for (int i = 0; i < ivec.size(); ++i) {
        tree[i].val = i;
    }
    memset(head, -1, sizeof head);
    int n;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        add_edge(a, b, 0), add_edge(b, a, 0);
    }
}