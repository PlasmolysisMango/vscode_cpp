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

typedef long long int ll;

const ll MAXN = 1e10;
ll N, M;
// ll selected[MAXN];

int q;

// ll lefts[MAXN], rights[MAXN];

int main()
{
    cin >> N >> M;
    unordered_set<ll> uset;
    ll smin = INT64_MAX, smax = -1;
    for (int i = 0; i < N; ++i) {
        ll select;
        cin >> select;
        if (select < smin)
            smin = select;
        else if (select > smax)
            smax = select;
        if (uset.find(select) == uset.end())
            uset.insert(select);
    }
    cin >> q;
    vector<ll> res;
    for (int i = 0; i < q; ++i) {
        ll left, right;
        cin >> left >> right;
        if (left > smax || right < smin) {
            res.push_back(left);
            continue;
        }
        ll j;
        for (j = left; j <= right; ++j) {
            if (uset.find(j) == uset.end()) {
                res.push_back(j);
                break;
            }
        }
        if (j == right+1)
            res.push_back(-1);
    }
    for (auto x : res)
        cout << x << endl;
}