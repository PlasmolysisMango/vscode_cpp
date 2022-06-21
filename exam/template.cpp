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

int snext[N];
void getNext(const string &t)
{
    memset(snext, -1, sizeof(snext));
    int j = -1;
    snext[0] = j;
    for (int i = 1; i < t.size(); ++i) {
        while (j >= 0 && t[i] != t[j+1])
            j = snext[j];
        if (t[i] == t[j+1])
            ++j;
        snext[i] = j;
    }
}

void kmp(const string &s, const string &t) 
{
    getNext(t);
    int j = -1;
    for (int i = 0; i < s.size(); ++i) {
        while (j >= 0 && s[i] != t[j+1])
            j = snext[j];
        if (s[i] == t[j+1])
            ++j;
        if (j == t.size()-1) {
            cout << i - j; // i-j起点，t.size()长度
        }
    }
}