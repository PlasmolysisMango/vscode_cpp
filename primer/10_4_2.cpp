#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <numeric>
#include <string>
#include <iterator>

using namespace std;

int main() 
{
    // istream_iterator<int> in(cin), eof;
    // cout << accumulate(in, eof, 0);

    vector<int> ivec{1, 2, 3};
    ostream_iterator<int> out(cout, " ");
    for (const auto &i : ivec) {
        *out++ = i; // 事实上完全等于out = i;
    }
}