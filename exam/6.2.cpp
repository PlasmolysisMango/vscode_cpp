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

string s;

deque<vector<int>> res;
int max0, max1;
void add(int num0, int num1, int i, int j) {
    if (num0 < max0 || num1 < max1)
        return;
    if (num0 == max0 && num1 == max1) {
        res.push_back({i, j});
        if (res.size() == 4) {
            res.pop_front();
            res.pop_front();
        }
        return;
    }
    max0 = num0;
    max1 = num1;
    res.push_back({i, j});
}

int main()
{
    max0 = max1 = -1;
    cin >> s;
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    // dp(i,j) 为i，j的字符串中1的数量, j-i+1-dp[i,j]即为0的数量
    for (int i = 0; i < s.size(); ++i)
        dp[i][i] = s[i] - '0';
    for (int i = 0; i < s.size(); ++i)
        for (int j = i + 1; j < s.size(); ++j) {
            if (s[j] == '1')
                dp[i][j] = dp[i][j - 1] + 1;
            else
                dp[i][j] = dp[i][j - 1];
            add(j - i + 1 - dp[i][j], dp[i][j], i, j);
        }
    bool flag = false;
    for (int i = 0; i < 2; ++i)
        for (auto x : res[i]) {
            if (!flag)
                flag = true;
            else
                cout << " ";
            cout << x+1;
        }
}