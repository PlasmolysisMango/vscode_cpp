#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() 
{
    vector<int> ivec;
    auto it = back_inserter(ivec);
    fill_n(it, 10, 233);
    for (const auto &i : ivec) {
        cout << i << " ";
    }
}