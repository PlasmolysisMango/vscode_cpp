#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstring>

using namespace std;

char *combine_char_s(const char a[], const char b[])
{
    size_t len = max(strlen(a), strlen(b));
    char *res = new char[len + 1];
    strcpy(res, a);
    strcat(res, b);
    return res;
}

int main()
{
    cout << combine_char_s("hello ", "world");
    
}