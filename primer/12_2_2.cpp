#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int n(20);
    allocator<string> alloc;
    auto const p = alloc.allocate(n);
    auto q = p;
    string s;
    while (cin >> s && q != p + n) 
        alloc.construct(q++, s);
    const size_t size = q - p;
    for (size_t i = 0; i != size; ++i) {
        cout << *(p + i) << " ";
    }
}