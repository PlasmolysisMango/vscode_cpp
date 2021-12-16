#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str("hello");
    for (auto it = str.begin(); it != str.end() && !isspace(*it); ++it) // 迭代器iterator
    {
        *it = toupper(*it);
    }
    cout << str << endl;
    return 0;
}