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

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> tree(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> tree[i];
    }
    vector<int> prefix(M, 0);
    long long res = 0;
    int sum = 0;
    for (auto t : tree) {
        sum = (sum + t) % M;
        res += prefix[sum]++;
        if (sum == 0)
            ++res;
    }
    cout << res;
}