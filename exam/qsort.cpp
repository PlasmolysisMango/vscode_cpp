#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

int medium3(vector<int> &nums, int left, int right) // 1 2
{
    int mid = (right - left) / 2 + left;
    if (nums[left] > nums[mid])
        swap(nums[left], nums[mid]);
    if (nums[mid] > nums[right])
        swap(nums[mid], nums[right]);
    if (nums[left] > nums[mid])
        swap(nums[left], nums[mid]);
    swap(nums[mid], nums[right - 1]);
    return nums[right - 1];
}

void qsort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;
    int pv = medium3(nums, left, right);
    int low = left, high = right - 1;
    while (1) {
        while (low <= right && nums[++low] < pv)
            ;
        while (high >= 0 && nums[--high] > pv)
            ;
        if (low < high)
            swap(nums[low], nums[high]);
        else
            break;
    }
    if (low <= right-1)
        swap(nums[low], nums[right - 1]);
    qsort(nums, left, low - 1);
    qsort(nums, low + 1, right);
}

int main()
{
    nums = {5, 5, 6, 7, 7, 8, 8, 5, 1, 2, 4, 4, 2, 1};
    qsort(nums, 0, nums.size() - 1);
    for (auto i : nums)
        cout << i << " ";
}