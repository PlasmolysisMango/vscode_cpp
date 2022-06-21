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
    int n, m;
    cin >> n >> m;
    vector<int> setA(n, 0), setB(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> setA[i];
    for (int i = 0; i < n; ++i)
        cin >> setB[i];
    sort(setA.begin(), setA.end());
    sort(setB.begin(), setB.end());
    int x = m - setA[0] + setB[0];
    cout << x;
}