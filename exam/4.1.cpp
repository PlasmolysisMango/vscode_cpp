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
#include <climits>

using namespace std;

int n;
string s;

int main()
{
    cin >> n >> s;
    vector<int> cnt(26, 0);
    int sum = 0;
    for (auto c : s) {
        cnt[c - 'a']++;
    }
    for (auto i : cnt) {
        if (i % 2 == 1)
            sum += i / 2 - 1;
        else
            sum += i / 2;
    }
    cout << sum;
}