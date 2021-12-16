#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>

using namespace std;

int main()
{
    // list<string> svec;
    // string tmp;
    // while (cin >> tmp) {
    //     svec.push_back(tmp);
    // }
    // for (auto iter = svec.cbegin(); iter != svec.end(); ++iter) {
    //     cout << *iter << " ";
    // }

    // list<int> lst{1, 2, 3, 4, 5, 6, 7, 8};
    // deque<int> dq1, dq2;
    // for (auto it = lst.cbegin(); it != lst.end(); ++it) {
    //     if (*it % 2)
    //         dq1.push_back(*it);
    //     else
    //         dq2.push_back(*it);
    // }
    // for (auto iter = dq2.cbegin(); iter != dq2.end(); ++iter) {
    //     cout << *iter << " ";
    // }

    // vector<int> vec;
    // auto iter = vec.begin();
    // int tmp;
    // while (cin >> tmp) {
    //     iter = vec.insert(iter, tmp);
    // }
    // for (auto iter = vec.cbegin(); iter != vec.end(); ++iter) {
    //     cout << *iter << " ";
    // }

    vector<int> iv = {1, 2, 3, 4, 5, 6, 7};
    // cout << iv.capacity() << " " << iv.size() << endl;
    int some_val = 2;
    vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
    for (auto iter = iv.cbegin(); iter != iv.cend(); ++iter) {
        cout <<*iter << "-" << &(*iter) << " ";
    }
    cout << endl;
    while (iter != mid)
    {
        if (*iter == some_val)
            iv.insert(iter, 2 * some_val); // 之所以可以正常工作，迭代器理解为指针，其存储的地址随着vector重新分配并未发生变化，
        cout<<*iter << "-" << &(*iter) << " "; // 尽管其指向的元素已经成为未分配的内存区域，是未定义的。
        ++iter;
    }
    cout << endl;
    for (auto iter = iv.cbegin(); iter != iv.cend(); ++iter) {
        cout<<*iter << "-" << &(*iter) << " ";
    }
}