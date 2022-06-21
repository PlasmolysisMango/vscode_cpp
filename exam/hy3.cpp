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

struct Point {
    int x = 0;
    int y = 0;
    Point() {}
    Point(int _x, int _y): x(_x), y(_y) {}
    bool operator == (const Point &rhs) {
        return x == rhs.x && y == rhs.y;
    }
    Point operator + (const Point &rhs) {
        Point res;
        res.x = x + rhs.x;
        res.y = y + rhs.y;
        return res;
    }
};

int N, M, K;
vector<vector<char>> graph;
// vector<vector<bool>> visited;

bool isValid(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M && graph[x][y] != 'W') { // 障碍物一定不能走
        return true;
    }
    return false;
}

Point st, ta;

int solve() {
    queue<Point> qu;
    qu.push(st);
    int epoch = 1;
    int step = -1;
    // int min_epoch = INT_MAX;
    // 队列中只可能是S E - M
    vector<Point> plist{Point(0, 1), Point(0, -1), Point(1, 0), Point(-1, 0)};
    while (!qu.empty()) 
    {
        int size = qu.size();
        ++step;
        for (int i = 0; i < size; ++i) {
            Point cur = qu.front();
            qu.pop();
            if (cur == ta) {
                return epoch;
            }
            // visited[cur.x][cur.y] = true;
            if (step == K && graph[cur.x][cur.y] == 'M') {
                continue;
            }
            graph[cur.x][cur.y] = 'W';
            for (auto &mov_p: plist) {
                Point tmp = cur + mov_p;
                if (isValid(tmp.x, tmp.y)) {
                    qu.push(tmp);
                }
            }
        }
        if (step == K) {
            epoch++;
            step = 0;
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> N >> M >> K;
        graph = vector<vector<char>>(N, vector<char>(M, '0'));
        // visited = vector<vector<bool>>(N, vector<bool>(M, false));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> graph[i][j];
                if (graph[i][j] == 'S') {
                    st = Point(i, j);
                }
                if (graph[i][j] == 'E') {
                    ta = Point(i, j);
                }
            }
        }
        cout << solve() << endl;
    }
}

// 1
// 1 5 4
// SMMME

// 迷宫问题，地图分起点、终点、监控点（回合结束时不能停留在监控点）、墙壁，每回合最多走K步，问最少几回合走到终点。
