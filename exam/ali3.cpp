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

int n;
map<double, int> smap;
vector<int> res;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        double a, b, c;
        cin >> a >> b >> c;
        double x = a / b;
        smap[x]++;
    }
    vector<pair<double, int>> vec(smap.begin(), smap.end());
    sort(vec.begin(), vec.end(), [](const pair<double, int> &l, const pair<double, int> &r)
         { return l.second > r.second; });
    int wh, bl;
    wh = bl = 0;
    for (int i = 0; i < vec.size(); ++i) {
        if (i % 2 == 0)
            wh += vec[i].second;
        else
            bl += vec[i].second;
    }
    cout << wh * bl;
}