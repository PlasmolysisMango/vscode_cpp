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

int n;
string s;

const int N = 1e2+1;
int nextX[N][N], nextY[N][N];
char box[N][N];

void getNext()
{
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        nextX[i][0] = x;
        for (int j = 1; j < n; ++j) {
            while (x != -1 && box[i][j] != box[i][x+1])
                x = nextX[i][x];
            if (box[i][j] == box[i][x+1])
                x++;
            nextX[i][j] = x;
        }
        x = -1;
        nextY[0][i] = x;
        for (int j = 1; j < n; ++j) {
            while (x != -1 && box[j][i] != box[x+1][i])
                x = nextY[x][i];
            if (box[j][i] == box[x+1][i])
                x++;
            nextY[j][i] = x;
        }
    }
}

int kmp()
{
    int cnt = 0;
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (int j = 0; j < n; ++j) {
            while (x != -1 && box[i][j] != s[x+1])
                x = nextX[i][x];
            if (box[i][j] == s[x+1])
                x++;
            if (x == s.size()-1) {
                cnt++;
                x = -1;
            }
        }
        x = -1;
        for (int j = 0; j < n; ++j) {
            while (x != -1 && box[j][i] != s[x+1])
                x = nextY[x][i];
            if (box[j][i] == s[x+1])
                x++;
            if (x == s.size()-1)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> box[i][j];
        }
        cin.get();
    }
    getNext();
    int cnt = kmp();
    cout << cnt;
    return 0;
}