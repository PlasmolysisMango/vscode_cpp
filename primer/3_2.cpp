#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string str("hello!!!");
    for (auto &c : str)
    {
        c = toupper(c);
    }
    cout << str << endl;
    return 0;
}
