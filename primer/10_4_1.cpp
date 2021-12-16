#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <string>
#include <iterator>

using namespace std;

int main() 
{
    // vector<int> ivec = {1, 1, 1, 3, 2, 1, 3, 5, 6, 1, 2, 4, 8, 5};
    // list<int> ilist;
    // sort(ivec.begin(), ivec.end()); // 必须进行事先排序
    // unique_copy(ivec.cbegin(), ivec.cend(), back_inserter(ilist)); // 仅仅是消除相邻重复项
    // for (const auto &i : ilist) {
    //     cout << i << " ";
    // }

    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> ilist;
    auto it = inserter(ilist, ilist.end());
    copy(ivec.cbegin(), ivec.cend(), it);
    for (const auto &i : ilist) {
        cout << i << " ";
    }
}