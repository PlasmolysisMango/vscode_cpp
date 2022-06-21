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

int main()
{
    string s;
    cin >> s;
    int size = s.size();
    int onecnt = 0;
    for (auto c:s) {
        onecnt += c - '0';
    }
    int zerocnt = size - onecnt;
    // 1 > 0, 0 > 1, 1 = 0‘
    char fc, sc;
    if (onecnt >= zerocnt) {
        fc = '1';
        sc = '0';
        for (int left = 0; left < size; ++left) {
            
        }
    }
    if (zerocnt >= onecnt) {
        fc = '0';
        sc = '1';

    }

}