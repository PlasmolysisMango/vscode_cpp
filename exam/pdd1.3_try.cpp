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
    // unordered_set<ll> uset;
    vector<ll> selected(N);
    for (int i = 0; i < N; ++i) {
        cin >> selected[i];
    }
    sort(selected.begin(), selected.end());
    selected.insert(selected.begin(), -1);
    selected.insert(selected.end(), INT64_MAX);
    cin >> q;
    vector<ll> res;
    for (int i = 0; i < q; ++i) {
        ll left, right;
        cin >> left >> right;
        ll beg = 1, end = selected.size() - 2;
        ll mid = -1;
        while (beg <= end) {
            mid = (end - beg) / 2 + beg;
            if (selected[mid] > left)
                end = mid;
            else if (selected[mid] <= left)
                beg = mid;
            if (beg == end)
                break;
        }
        

    }

        for (auto x : res)
            cout << x << endl;
}