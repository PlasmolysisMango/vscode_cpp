#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    vector<int> ivec;
    int tmp;
    while (cin >> tmp) {
        ivec.push_back(tmp);
    }
    int cnt = accumulate(ivec.begin(), ivec.end(), 0);
    cout << "Sum = " << cnt;
}