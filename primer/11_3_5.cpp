#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
// #include "output_container.h"

using namespace std;

bool find_erase(map<string, string> &ssmap, const string &author)
{
    auto it = ssmap.find(author);
    if (it != ssmap.end()) {
        ssmap.erase(it);
        return true;
    }
    else
        return false;
}

void print(const map<string, string> &ssmap) 
{
    for (auto beg = ssmap.cbegin(); beg != ssmap.cend(); ++beg) {
        cout << beg->first << ": " << beg->second << endl;
    }
}

int main()
{
    map<string, string> author_book;
    author_book["jack"] = "c++";
    find_erase(author_book, "c");
    print(author_book);
}