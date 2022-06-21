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

int N;

int main()
{
    cin >> N;
    vector<int> stones(N);
    for (int i = 0; i < N;++i) {
        cin >> stones[i];
    }
    unordered_map<int, vector<int>> umap; // 颜色，位置序列
    for (int i = 0; i < N; ++i) {
        int color = stones[i];
        if (umap[color].size() >= 1 && umap[color].front() == -1) {
            continue;
        }
        if (umap[color].size() < 2) {
            umap[color].push_back(i);
        }
        else {
            vector<int> &tmp = umap[color];
            int len = tmp[1] - tmp[0];
            if (i - tmp.back() == len) {
                tmp.push_back(i);
            }
            else {
                tmp.clear();
                tmp.push_back(-1);
            }
        }
    }
    vector<pair<int, int>> res;
    for (auto p : umap) {
        if (p.second.size() >= 2) {
            res.push_back({p.first, p.second[1] - p.second[0]});
        }
        else if (p.second.size() == 1 && p.second[0] != -1) {
            res.push_back({p.first, 0});
        }
    }
    cout << res.size() << endl;
    sort(res.begin(), res.end(), [](const pair<int, int> &lhs, const pair<int, int> &rhs)
         { return lhs.first < rhs.first; });
    for (auto p : res) {
        cout << p.first << " " << p.second << endl;
    }
}