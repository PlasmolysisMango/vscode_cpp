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

int main()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<vector<int>> v1(m1, vector<int>(2, 0)); 
    vector<vector<int>> v2(m2, vector<int>(2, 0));
    for (int i = 0; i < m1; ++i) {
        cin >> v1[i][0];
    }
    for (int i = 0; i < m1; ++i) {
        cin >> v1[i][1];
    }
    for (int i = 0; i < m2; ++i) {
        cin >> v2[i][0];
    }
    for (int i = 0; i < m2; ++i) {
        cin >> v2[i][1];
    }
    auto cmp = [](vector<int> &lhs, vector<int> &rhs) -> bool
    { if (lhs[0] == rhs[0]) return lhs[1] < rhs[1];  return lhs[0] < rhs[0]; };
    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    int res = 0;
    int index1 = 0, index2 = 0;
    vector<vector<int>> v3, v4;
    v3.push_back(v1[0]), v4.push_back(v2[0]);
    for (int i = 1; i < v1.size(); ++i) {
        if (v1[i][0] <= v3.back()[1]) {
            v3.back()[1] = v1[i][1];
        }
        else {
            v3.push_back(v1[i]);
        }
    }
    for (int i = 1; i < v2.size(); ++i) {
        if (v2[i][0] <= v4.back()[1]) {
            v4.back()[1] = v2[i][1];
        }
        else {
            v4.push_back(v2[i]);
        }
    }
    while (index1 < v3.size() && index2 < v4.size())
    {
        int left1 = v3[index1][0], right1 = v3[index1][1];
        int left2 = v4[index2][0], right2 = v4[index2][1];
        if (left2 > right1)
        {
            ++index1;
        }
        else if (left1 > right2)
        {
            ++index2;
        }
        else
        {
            res += min(right1, right2) - max(left1, left2) + 1;
            if (left1 < left2)
                ++index1;
            else
                ++index2;
        }
    }
    cout << res;
}