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

int N;

int main() 
{
    cin >> N;
    // int lenth = N / 9 + N % 9 ? 1 : 0;
    string s;
    int i;
    for (i = 9; i > 0 && N > i; i--) {
        s.push_back((i+'0'));
        N -= i;
    }
    if (N <= i) {
        s.push_back((N+'0'));
        reverse(s.begin(), s.end());
        cout << s;
    }
    else
        cout << "-1";
}