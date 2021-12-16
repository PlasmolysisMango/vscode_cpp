#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str("hello!!!");
    decltype(str.size()) punct_count = 0;
    for (auto c : str)
    {
        if (ispunct(c))
            ++punct_count;
    }
    cout << punct_count << endl;
    return 0;
}
