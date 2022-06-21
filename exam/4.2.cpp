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

int l, r;

int getDigitSum(int x)
{
    int sum = 0;
    while (x)
    {
        int d = x % 10;
        sum += d;
        x /= 10;
    }
    return sum;
}

int solve()
{
    // int x = l;
    // vector<int> digit;
    // int sum = 0;
    // while (x)
    // {
    //     int d = x % 10;
    //     digit.push_back(d);
    //     sum += d;
    //     x /= 10;
    // }
    int cnt = 0;
    // int digitIndex = 0;
    int presum = getDigitSum(l - l % 10);
    int sum;
    while (l <= r) {
        if (l % 10 == 0)
            presum = getDigitSum(l);
        sum = presum + l % 10;
        if (l % sum == 1)
            cnt++;
        ++l;
    }
    return cnt;
}

int main()
{
    int t;
    cin >> t;
    vector<int> ans;
    while (t--) {
        cin >> l >> r;
        int a = solve();
        ans.push_back(a);
    }
    for (auto i:ans)
        cout << i << endl;
}