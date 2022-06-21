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

const int N = 1e5 + 10, M = N * 2;
struct EdgeNode {
    int next;
    int to;
} edge[M];

int head[N], idx = 0;
int n, m;

void add(int a, int b) 
{
    edge[idx].to = b;
    edge[idx].next = head[a];
    head[a] = idx++;
}

bool visited[N];
void dfs(int u) 
{
    visited[u] = true;
    cout << u << " ";
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int son = edge[i].to;
        if (!visited[son])
            dfs(son);
    }
}

int main() 
{
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
}