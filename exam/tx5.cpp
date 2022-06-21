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

int main()
{
    cin >> n >> m;
    vector<int> num(n);
    for (int i = 0; i < n; ++i)
        cin >> num[i];
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    // 每天两种状态，0持有，1卖出
    // dp[0][0] = m >= num[0] ? m - num[0] : m;
    // dp[0][1] = m;
    // for (int i = 1; i < n; ++i) {

    // }
    return m;
}