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
    // vector<int> ivec{1, 2, 3};
    // for (auto rit = ivec.crbegin(); rit != ivec.crend(); ++rit) {
    //     cout << *rit << " ";
    // }
    // cout << endl;

    // for (auto it = --ivec.cend(); it != ivec.cbegin() - 1; --it) {
    //     cout << *it << " ";
    // }
    // cout << endl;

    // list<int> ilist{1, 2, 0, 2, 0};
    // auto rit = find(ilist.crbegin(), ilist.crend(), 0);
    // cout << *rit;

    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto rit_beg = ivec.crbegin() + 4, rit_end = ivec.crend() - 2;
    list<int> ilist;
    copy(rit_beg, rit_end, back_inserter(ilist));
    ostream_iterator<int> out(cout, " ");
    copy(ilist.cbegin(), ilist.cend(), out);
}