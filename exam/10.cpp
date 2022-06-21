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

using namespace std;

string s;
int k;
vector<string> res;

void solve()
{
    if (s.size() == 1)
        return;
    int isSwap = true;
    while (isSwap && k) {
        isSwap = false;
        for (int i = 1; i < s.size() && k; ++i) {
            if (s[i-1] > s[i]) {
                swap(s[i - 1], s[i]);
                isSwap = true;
                k--;
            }
        }
    }
    if (k > 0) {
        if (k % 2 == 1)
            swap(s[s.size() - 1], s[s.size() - 2]);
    }
    res.push_back(s);
}

int n;
int main()
{
    cin >> n;
    while (n--) {
        cin >> s >> k;
        solve();
    }
    bool flag = false;
    for (auto s : res) {
        if (!flag)
            flag = !flag;
        else
            cout << endl;
        cout << s;
    }
}