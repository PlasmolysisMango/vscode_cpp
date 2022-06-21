#include <iostream>
#include <vector>

using namespace std;

void percDown(vector<int> &nums, int p, int size)
{
    int c;
    int tmp = nums[p];
    for (; p*2+1 < size; p = c) {
        c = 2 * p + 1;
        if (c < size-1 && nums[c+1] > nums[c])
            c++;
        if (tmp < nums[c])
            nums[p] = nums[c];
        else
            break;
    }
    nums[p] = tmp;
}

void heapsort(vector<int> &nums, int left, int right)
{
    int size = right - left + 1;
    for (int i = (size - 2) / 2; i >= 0; --i)
        percDown(nums, i, size);
    for (int i = nums.size()-1; i > 0; --i) {
        swap(nums[0], nums[i]);
        percDown(nums, 0, i);
    }
}

int main() 
{
    vector<int> nums = {2,1};
    heapsort(nums, 0, nums.size()-1);
    for (auto i : nums)
        cout << i << " ";
}