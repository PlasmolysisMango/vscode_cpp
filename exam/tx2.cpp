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

vector<bool> v;
void primes(int n) {
    for (int i = 2; i <=n ; i++) {
        if (v[i])
            continue;
        for (int j = i; j <= n/i; j++)
            v[i*j] = true;
    }
}

int getNumber(vector<int>& a) {
        // write code here
    int n = a.size();
    v.resize(n+1);
    v[1] = true;
    primes(n);
    int size = a.size();
    while (size != 1) {
        int slow = 0;
        for (int i = 1; i <= size; ++i)  {
            if (!v[i]) {
                a[slow++] = a[i-1];
            }
        }
        size = slow;
    }
    return a[0];
}

int main()
{
    vector<int> a{1, 2, 3, 4};
    int res = getNumber(a);
    return 0 ;
}