#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> nums(10);
    for (decltype(nums.size()) i = 0; i != nums.size(); ++i) // 下标方式
        nums[i] = i;
    for (auto it = nums.begin(); it != nums.end(); ++it) // 迭代器
        *it *= 2;
    for (auto n : nums) // 范围for
    {
        cout << n << endl;
    }
    return 0;
}