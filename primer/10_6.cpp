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
    // list<string> slist{"hello", "world", "hello", "c++", "java", "c++", "java"};
    // slist.sort();
    // ostream_iterator<string> out(cout, " ");
    // slist.unique();
    // copy(slist.cbegin(), slist.cend(), out);

    vector<int> ivec{1, 2, 3};
    auto it = remove(ivec.begin(), ivec.end(), 2);
    ostream_iterator<int> out(cout, " ");
    copy(ivec.begin(), it, out);
}