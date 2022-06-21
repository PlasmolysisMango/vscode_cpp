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

int T;

int N, M;

char graph[501][501];
int visited[501][501]; // 0 1未来过 来过

int sx, sy, tx, ty;

bool check(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M)
        return true;
    return false;
}

bool checkav(int x, int y) {
    if (check(x, y) && graph[x][y] != '0')
        return true;
    return false;
}


int solve() {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    int cnt = -1;
    while (!q.empty()) {
        int size = q.size();
        ++cnt;
        for (int i = 0; i < size; ++i) {
            auto [x, y] = q.front();
            q.pop();
            if (visited[x][y])
                continue;
            if (x == tx && y == ty)
                return cnt;
            visited[x][y] = 1;
            int nx, ny;
            if (check(x-1, y) && graph[x-1][y] != '0') {
                nx = x - 2;
                ny = y + 1;
                if (checkav(nx, ny))
                    q.push({nx, ny});
                ny = y - 1;
                if (checkav(nx, ny))
                    q.push({nx, ny});
            }
            if (check(x+1, y) && graph[x+1][y] != '0') {
                nx = x + 2;
                ny = y + 1;
                if (checkav(nx, ny))
                    q.push({nx, ny});
                ny = y - 1;
                if (checkav(nx, ny))
                    q.push({nx, ny});
            }
            if (check(x, y-1) && graph[x][y-1] != '0') {
                nx = x + 1;
                ny = y - 2;
                if (checkav(nx, ny))
                    q.push({nx, ny});
                nx = x - 1;
                if (checkav(nx, ny))
                    q.push({nx, ny});
            }
            if (check(x, y+1) && graph[x][y+1] != '0') {
                nx = x + 1;
                ny = y + 2;
                if (checkav(nx, ny))
                    q.push({nx, ny});
                nx = x - 1;
                if (checkav(nx, ny))
                    q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main()
{
    cin >> T;
    vector<int> res;
    while (T--) {
        memset(graph, 0, sizeof graph);
        memset(visited, 0, sizeof visited);
        cin >> N >> M;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> graph[i][j];
                if (graph[i][j] == 'K') {
                    sx = i;
                    sy = j;
                }
                else if (graph[i][j] == 'T') {
                    tx = i;
                    ty = j;
                }
            }
        }
        int r = solve();
        res.push_back(r);
    }
    for (auto r : res) {
        cout << r << endl;
    }
}