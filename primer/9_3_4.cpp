#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <string>

using namespace std;

bool find_and_insert(forward_list<string> &flist, const string &s, const string &d) {
    auto prev = flist.before_begin(), curr = flist.begin();
    while (curr != flist.end()) {
        if (*(curr) == s) {
            curr = flist.insert_after(curr, d);
            ++prev;
            return true;
        }
        else {
            ++curr;
            ++prev;
        }
    }
    flist.insert_after(prev, d);
    return false;
}

int main() 
{
    // list<string> slist = {"qwe", "233"};
    // auto elem1 = slist.begin(), elem2 = slist.end();
    // elem1 = elem2;
    // elem1 = slist.erase(elem1, elem2);
    // for (const auto &s : slist) {
    //     cout << s << " ";
    // }

    // forward_list<int> flist = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // for (auto prev = flist.before_begin(), curr = flist.begin(); curr != flist.end(); ) {
    //     if (*curr % 2) {
    //         curr = flist.erase_after(prev);
    //     }
    //     else {
    //         ++curr;
    //         ++prev;
    //     }
    // }
    // for (const auto &s : flist) {
    //     cout << s << " ";
    // }

    forward_list<string> flist{"hello", "c++", "world"};
    string s = "c++", s2 = "java", d = "python";
    find_and_insert(flist, s2, d);
    for (const auto &s : flist) {
        cout << s << " ";
    }
}