#include <iostream>
#include <vector>
using namespace std;

vector<int> vec{1, 2, 3, 4, 5};

bool find(vector<int>::iterator beg, vector<int>::iterator end, int x)
{
    for (; beg != end; ++beg) {
        if (*beg == x) {
            return true;
        }
    }
    return false;
}

vector<int>::iterator findref(vector<int>::iterator beg, vector<int>::iterator end, int x)
{
    for (; beg != end; ++beg) {
        if (*beg == x) {
            return beg;
        }
    }
    return end;
}

int main()
{
    auto beg = ++vec.begin(), end = vec.end();
    int x = 1;
    cout << (findref(beg, end, x) != end ? "Yes" : "No") << endl;
}

