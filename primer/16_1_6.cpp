#include "MySharedPtr.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void test(MySharedPtr<string> t)
{
    return;
}

int main()
{
    string *s = new string("2333");
    MySharedPtr<string> ptr_s(s);
    test(ptr_s);
    // int *a = new int(3); 
    std::cout << *ptr_s;
}