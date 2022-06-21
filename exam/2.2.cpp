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

int n, m;
const int N = 1e5 + 10, M = 2 * N;
struct EdgeNode {
    int to;
    int next;
    int weight;
} edge[M];

int head[N], idx;

void add(int a, int b, int w) 
{
    edge[idx].to = b;
    edge[idx].next = head[a];
    edge[idx].weight = w;
    head[a] = idx++;
}

int dist[N];
int find() 
{
    int maxIdx = -1, maxdist = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] && dist[i] > maxdist) {
            maxdist = dist[i];
            maxIdx = i;
        }
    }
    return maxIdx;
}

int prim()
{
    for (int i = head[1]; ~i; i = edge[i].next) {
        dist[edge[i].to] = edge[i].weight; // 初始化dist数组
    }
    dist[1] = 0;
    int minEdge = INT_MAX;
    while (1) {
        int v = find();
        if (v == -1)
            break;
        minEdge = min(minEdge, dist[v]);
        dist[v] = 0;
        for (int i = head[v]; ~i; i = edge[i].next) {
            if (dist[edge[i].to] && edge[i].weight > dist[edge[i].to]) // 更新dist
                dist[edge[i].to] = edge[i].weight;
        }
    }
    return minEdge;
}

int main()
{
    cin >> n >> m;
    memset(head, -1, sizeof head);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w);
        add(b, a, w);
    }
    int maxedge = prim();
    cout << maxedge;
}