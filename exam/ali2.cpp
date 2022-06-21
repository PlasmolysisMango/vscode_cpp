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

int n;
vector<int> nums(5, 0);
vector<int> res;
void mycount()
{
    sort(nums.begin(), nums.end(), greater<int>());
    int cnt = 0;
    cnt += nums[3];
    if (nums[2] - nums[3] != 0 && nums[4] != 0)
        cnt += min(nums[2] - nums[3], nums[4]);
    res.push_back(cnt);
}

int main() 
{
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 5; ++i)
            cin >> nums[i];
        mycount();
    }
    bool flag = false;
    for (auto x : res) {
        if (!flag)
            flag = true;
        else
            cout << endl;
        cout << x;
    }
}