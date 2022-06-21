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

int n;

int main()
{
    unordered_map<ll, ll> red, blue; // 数值-数量
    cin >> n;
    vector<ll> a(n);
    string color;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> color;
    for (int i = 0; i < n; ++i) {
        if (color[i]=='B') {
            ++blue[a[i]];
        }
        else {
            ++red[a[i]];
        }
    }
    ll res = 0;
    for (auto bluepa: blue) {
        auto it = red.find(bluepa.first);
        if (it != red.end()) {
            res += bluepa.second * (it->second);
        }
    }
    cout << res;
}
