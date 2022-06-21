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

string s;

int main()
{
    cin >> s;
    vector<int> dp(s.size(), 0);
    // 表示考虑i-1结尾的字符串的最高分数；
    dp[0] = 0;
    dp[1] = 0;
    if (s.size() >= 2 && abs(s[1]-s[0]) <= 1) 
        dp[1] = (s[1] - 'a' + s[0] - 'a' + 2);
    for (int i = 2; i < s.size(); ++i) {
        if (abs(s[i]-s[i-1]) <= 1) {
            dp[i] = max(dp[i - 2] + (s[i] - 'a' + s[i - 1] - 'a' + 2), dp[i-1]);
        }
        else
            dp[i] = dp[i - 1];
    }
    cout << dp[s.size() - 1];
}