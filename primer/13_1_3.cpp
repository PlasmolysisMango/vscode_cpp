#include <iostream>
using namespace std;

class X {
public:
    X() { cout << "X()" << endl; }
    X(const X &) { cout << "X(const X &)" << endl; }
    ~X() { cout << "~X()" << endl; }
    X &operator=(const X &) { cout << "X &operator=(const X&)" << endl;
        return *this;
    }
};

int main()
{
    X x;
    X y(x);
    X z = x, b;
    b = x;
    X a = X();
}