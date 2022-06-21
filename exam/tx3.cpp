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

int n;
string s;
using ull = unsigned long long;

int main()
{
    cin >> n;
    cin >> s;
    // 0 进攻 1 防守
    ull atk, def;
    atk = def = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i]=='0')
            atk += i + 1;
        else
            def += i + 1;
    }
    ull res = def;
    ull natk = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0')
            natk += i + 1;
        else
            def -= i + 1;
        if (def > natk) {
            res = min(res, def - natk);
        }
        else
            res = min(res, natk - def);
    }
    cout << res;
}