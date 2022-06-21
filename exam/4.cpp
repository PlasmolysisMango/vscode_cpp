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
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n, 1));
    int cnt = 0;
    vector<int> s(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        dp[i][i] = s[i];
        if (dp[i][i] == 1)
            ++cnt;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
                dp[i][j] = dp[i][j-1] * s[j];
                if (dp[i][j] == 1)
                    ++cnt;
        }
    }
    cout << cnt;
}