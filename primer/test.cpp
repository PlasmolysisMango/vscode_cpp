#include <queue>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool backtracking(vector<int> &nums, int startIndex, int sum)
    {
        for (int i = startIndex; i < nums.size() && nums[i] <= sum; ++i) {
            if (nums[i] == sum)
                return true;
            if (nums[i] < sum && backtracking(nums, i+1, sum - nums[i]))
                return true;
        }
        return false;
    }
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for_each(nums.begin(), nums.end(), [&](const int lhs){sum += lhs;});
    if (sum & 1)
        return false;
    sum = sum >> 1;
    sort(nums.begin(), nums.end());
    return backtracking(nums, 0, sum);
}

int main()
{
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7};
    auto x = canPartition(ivec);
    cout << (x ? "true" : "false");
    return 0;
}