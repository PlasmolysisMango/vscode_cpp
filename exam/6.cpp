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

const int N = 1e5 + 100, M = N * 2;
struct EdgeNode {
    int to;
    int next;
} edge[M];

int head[N], idx = 0;

void add(int a, int b) 
{
    edge[idx].to = b;
    edge[idx].next = head[a];
    head[a] = idx++;
}

bool visited[N];
int dfs(int u) 
{
    visited[u] = true;
    int cnt = 1;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int son = edge[i].to;
        if (!visited[son])
            cnt += dfs(son);
    }
    return cnt;
}

int n;
int main()
{
    cin >> n;
    memset(head, -1, sizeof head);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    int res = -1;
    visited[1] = true;
    for (int i = head[1]; ~i; i = edge[i].next) {
        res = max(res, dfs(edge[i].to));
    }
    cout << res;
}