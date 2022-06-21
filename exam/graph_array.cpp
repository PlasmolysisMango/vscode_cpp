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

using namespace std;

const int N = 1e5, M = 2 * N;
struct EdgeNode {
    int to;
    int next;
    int weight;
} edge[M];

int head[N], idx;

// 初始化 memset(head, -1, sizeof head);

void add(int from, int to, int weight) 
{
    edge[idx].to = to;
    edge[idx].weight = weight;
    edge[idx].next = head[from];
    head[from] = idx++;
}

bool visited[N];

void dfs(int s)
{
    if (visited[s])
        return;
    visited[s] = true;
    printf("%d ", s);
    for (int i = head[s]; ~i; i = edge[i].next) {
        int son = edge[i].to;
        dfs(son);
    }
}

void bfs(int s) 
{
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (visited[v])
            continue;
        visited[v] = true;
        printf("%d ", v);
        for (int i = head[v]; ~i; i = edge[i].next) {
            int son = edge[i].to;
            q.push(son);
        }
    }
}

int knext[N];

void getNext(const string &t) 
{
    memset(knext, 0, sizeof knext);
    int j = -1;
    knext[0] = -1;
    for (int i = 1; i < t.size(); ++i) {
        while (j != -1 && t[i] != t[j+1])
            j = knext[j];
        if (t[i] == t[j+1])
            j++;
        knext[i] = j;
    }
}

int kmp(const string &s, const string &t) 
{
    getNext(t);
    int j = -1;
    for (int i = 0; i < s.size(); ++i) {
        while (j != -1 && s[i] != t[j+1])
            j = knext[j];
        if (s[i] == t[j+1])
            j++;
        if (j == t.size()-1)
            return i - j;
    }
    return -1;
}

int main()
{
    // memset(head, -1, sizeof head);
    // int n;
    // cin >> n;
    // while (n--) {
    //     int a, b, w;
    //     cin >> a >> b >> w;
    //     add(a, b, w);
    // }
    // dfs(0);
    // bfs(0);
    printf("%d", kmp("helloworld", "java"));
}