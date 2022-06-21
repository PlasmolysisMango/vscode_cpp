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

int res;
int sum;
int maxSum;
unsigned long long cnt;
int k1, k2;

bool check()
{
    return (sum % k1 == 0) && (sum % k2 != 0);
}

void bt(vector<int> &nums, int startIndex) 
{
    if (startIndex == nums.size())
        return;
    for (int i = startIndex; i < nums.size(); ++i) {
        sum += nums[i];
        if (check()) {
            if (sum > maxSum) {
                maxSum = sum;
                cnt = 1;
            }
            else if (sum == maxSum) {
                ++cnt;
            }
            bt(nums, i + 1);
        }
        sum -= nums[i];
    }
}

int main()
{
    int n;
    cin >> n >> k1 >> k2;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    res = 0;
    sum = 0;
    cnt = 0;
    maxSum = INT_MIN;
    bt(nums, 0);
    cout << maxSum << " " << cnt % 998244353;
}