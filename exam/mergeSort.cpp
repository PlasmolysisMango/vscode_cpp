#include <iostream>
#include <vector>

using namespace std;

vector<int> tmp;

void mergeSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;
    // if (right - left == 1 && nums[left] > nums[right])
    //     swap(nums[left], nums[right]);
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    int idx = left, leftIdx = left, rightIdx = mid+1;
    while (leftIdx <= mid || rightIdx <= right) {
        if (leftIdx > mid)
            tmp[idx++] = nums[rightIdx++];
        else if (rightIdx > right)
            tmp[idx++] = nums[leftIdx++];
        else {
            if (nums[leftIdx] < nums[rightIdx])
                tmp[idx++] = nums[leftIdx++];
            else
                tmp[idx++] = nums[rightIdx++];
        }
    }
    for (idx = left; idx <= right; ++idx)
        nums[idx] = tmp[idx];
}

int main()
{
    vector<int> nums{4, 3, 2, 4, 1, 5, 8, 5, 1, 0};
    tmp = vector<int>(nums.size(), 0);
    mergeSort(nums, 0, nums.size() - 1);
    for (auto i : nums)
        cout << i << " ";
}