#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is5longer(const string &s)
{
    return s.size() >= 5;
}

int main()
{
    vector<string> svec{"hello", "world", "cool", "java", "c++", "python", "pasuasfd"};
    auto it = partition(svec.begin(), svec.end(), [](const string &s) -> bool
                        { return s.size() >= 5; });
    for (auto beg = svec.cbegin(); beg != it; ++beg)
    {
        cout << *beg << " ";
    }
}