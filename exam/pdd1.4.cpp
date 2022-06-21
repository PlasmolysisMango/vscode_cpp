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

int n, m, x;

int main()
{
    cin >> m >> n >> x;
    vector<int> time(m);
    for (int i = 0; i < m; ++i)
        cin >> time[i];
    sort(time.begin(), time.end());
    time.insert(time.begin(), 0);
    vector<int> dp(m + 1, INT_MAX); //dp[i]第i辆
    dp[0] = -x;
    dp[1] = time[1] + x;
    for (int i = 2; i <= m; ++i) {
        for (int j = max(0, i - n); j < i; ++j) {
            dp[i] = min(dp[i], max(dp[j] + x, time[i]) + x);
        }
    }
    cout << dp[m];
}