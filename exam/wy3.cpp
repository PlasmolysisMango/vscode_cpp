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

int n;
int jishu, oushu;

int get_ji()
{
    if (jishu + 2 <= n) {
        jishu += 2;
        return jishu;
    }
    else
        return -1;
}

int get_ou()
{
    if (oushu + 2 <= n) {
        oushu += 2;
        return oushu;
    }
    else
        return -1;
}

int main()
{
    cin >> n;
    jishu = -1, oushu = 0;
    vector<int> res(n, 0);
    if (n % 2 == 0)
        res[0] = get_ji();
    else
        res[0] = get_ou();
    for (int i = 1; i < n; ++i) {
        int idx = (i - 1) / 2;
        if (res[idx] % 2 == 1)
            res[i] = get_ou();
        else {
            if (idx * 2 + 1 == i) // 左子树
                res[i] = get_ou();
            else
                res[i] = get_ji();
            if (res[i] == -1) {
                res[i] = get_ou() == -1 ? get_ji() : get_ou();
            }
        }
    }
    for (auto x : res) {
        cout << x << " ";
    }
}