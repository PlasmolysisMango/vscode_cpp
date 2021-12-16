#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> *ptrToivec()
{
    auto p = new vector<int>;
    return p;
}

void read(vector<int> *const p)
{
    int n;
    while (cin >> n) {
        p->push_back(n);
    }
}

void print(vector<int> *const p)
{
    ostream_iterator<int> out(cout, " ");
    copy(p->cbegin(), p->cend(), out);
}

void process(shared_ptr<int> s_ptr)
{
    return;
}

int main()
{
    vector<int> *ptr = ptrToivec();
    read(ptr);
    print(ptr);
    delete ptr;
    // process(new int());
}