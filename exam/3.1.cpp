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
#include <climits>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int n, m;

struct EdgeNode {
    int to;
    int next;
    int weight;
} edge[M];

int head[N], idx, price[N];

void add(int a, int b, int w) {
    edge[idx].to = b;
    edge[idx].weight = w;
    edge[idx].next = head[a];
    head[a] = idx++;
}

bool visited[N];
bool onPath[N];
bool cycle = false;
void dfs(int u) {
    
    if (onPath[u]) {
        cycle = true;20
    }
    if (cycle || visited[u])
        return;
    visited[u] = true;    
    onPath[u] = true;
    cout << edge[head[u]].weight << " ";
    for (int i = head[u]; ~i; i = edge[i].next) {
        int son = edge[i].to;
        dfs(son);
    }
    onPath[u] = false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> price[i];
    memset(head, -1, sizeof head);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w);
        add(b, a, w);
    }
    dfs(1);
    if (cycle)
        cout << "yes";
}