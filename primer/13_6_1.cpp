#include <iostream>
#include <vector>
#include "MyString.h"
#include <string>

int main()
{

    MyString s1("xxx");
    MyString s2 = s1, s3;
    s3 = s2;
    std::cin >> s3 >> s2;
    std::cout << s3 << " and " << s2 << std::endl;
}