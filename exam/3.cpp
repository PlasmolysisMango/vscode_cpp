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

bool judge(int num)
{
    if (num % 11 != 0)
        return false;
    int digit;
    int cnt = 0;
    while (num) {
        digit = num % 10;
        if (digit == 1) {
            ++cnt;
            if (cnt == 2)
                return true;
        }
        num /= 10;
    }
    return false;
}

int main() 
{
    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        string ans = judge(num) ? ("yes") : ("no");
        cout << ans << endl;
    }
}