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

int n, m;
vector<vector<int>> vmap;
vector<vector<bool>> visited;

int minCost = INT_MAX;
void bt(int i, int j, int cost) 
{
    visited[i][j] = true;
    if (i == n-1 && j == m-1) {
        minCost = min(minCost, cost);
        visited[i][j] = false;
        return;
    }
    if (i < 0 || j < 0) {
        visited[i][j] = false;
        return;
    }
    if (i > n || j > m) {
        visited[i][j] = false;
        return;
    }
    if (i+1 < n) {
        // visited[i + 1][j] = true;
        if (!visited[i + 1][j])
            bt(i + 1, j, cost + (vmap[i + 1][j] == vmap[i][j] ? 1 : 2));
        // visited[i + 1][j] = false;
    }
    if (j+1 < m) {
        // visited[i][j+1] = true;
        if (!visited[i][j+1])
            bt(i, j+1, cost + (vmap[i][j+1] == vmap[i][j] ? 1 : 2));
        // visited[i][j+1] = false;
    }
    if (i-1 >= 0) {
        // visited[i - 1][j] = true;
        if (!visited[i-1][j])
            bt(i-1, j, cost + (vmap[i-1][j] == vmap[i][j] ? 1 : 2));
        // visited[i - 1][j] = false;
    }
    visited[i][j] = false;
}

int main() {
    cin >> n >> m;
    vmap = vector<vector<int>>(n, vector<int>(m, 0));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            cin >> vmap[i][j];
    bt(0, 0, 0);
    cout << minCost;
}