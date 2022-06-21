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
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    ll size = s.size();
    if (size == 0) {
        cout << 0;
        return 0;
    }
    vector<vector<ll>> dp(2, vector<ll>(9, 0)); // dp[i][j] 以s[0]-s[i]的子序列中，sum % 9 == j 的数量
    // num = x, dp[i][j] = dp[i-1][9-x]
    //  1188
    const ll MOD = 1e9 + 7;
    ll res = (s[0] == '9') ? 1 : 0;
    if (s[0]-'0' >= 1 && s[0]-'0' <= 9) {
        dp[0][s[0] - '0'] = 1;
    }
    for (int i = 1; i < size; ++i) {
        int num = s[i] - '0';
        if (num != 0 && num != 9) {
            res += dp[0][9 - num];
        }
        else 
            res = res * 2 + 1;
        res %= MOD;
        dp[1] = vector<ll>(dp[0].begin(), dp[0].end());
        for (int j = 1; j <= 8; ++j) {
            if ((j+num) % 9)
                dp[1][(j + num) % 9] += dp[0][j];
        }      
        dp[1][num] += 1;
        dp[0] = vector<ll>(dp[1].begin(), dp[1].end());
    }
    cout << res;
}