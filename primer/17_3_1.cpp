#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    string pattern = "[[:alnum:]]*[^c]ei[[:alnum:]]*$";
    string str = "ceishi height";
    smatch result;
    regex r(pattern);
    if (regex_search(str, result, r))
        cout << result.str();
}