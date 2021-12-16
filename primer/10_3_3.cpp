#include <iostream>

using namespace std;

int main()
{
    int a = 5;
    auto f = [&a]() mutable -> bool
    {
        if (a)
        {
            while (a)
                --a;
            return false;
        }
            
        else
            return true;
    };
    cout << (f() ? "Is 0" : "Not 0") << " " << a;
}