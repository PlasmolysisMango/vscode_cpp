#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int> &nums, int left, int right)
{
    int size = right - left + 1;
    for (int p = 1; p < size; ++p) {
        int tmp = nums[p], i;
        for (i = p; i > 0 && tmp < nums[i - 1]; --i)
            nums[i] = nums[i-1];
        nums[i] = tmp;
    }
}

int main()
{
    vector<int> nums{4, 3, 5, 2, 4, 1};
    insertSort(nums, 0, nums.size() - 1);
    for (auto i : nums)
        cout << i << " ";
}