#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> nums{1,2,3,4};
    auto beg = nums.begin();
    auto end = nums.end();
    auto mid = nums.begin() + (end - beg) / 2;
    int sought(5);
    while (mid != end && *mid != sought)
    {
        if (sought < *mid)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg) / 2;
    }
    cout << *mid << endl;
    
    return 0;
}