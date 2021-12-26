#include <iostream>
#include <string>

using namespace std;

template <typename T, typename... Args>
void foo(const T &t, const Args &...rest)
{
    cout << "Args: " << sizeof...(Args) << endl;
    cout << "args: " << sizeof...(rest) << endl;
}

class Test {
public:
    string &getref() const { return *s; }
    string *getptr() const { return s; }
    Test() : s(nullptr) { }
    explicit Test(const string &s): s(new string(s)) { }
    string &get_str() const { return *s; }
    // Test &get_self() const { return *this; }
    ~Test(){ if (s)
            delete s;
    }

private:
    string *s;
};

int main()
{
    // int i = 0;
    // double d = 3.14;
    // string s = "how dare you";
    // foo(i, d);
    string s("hello");
    Test t(s);
    auto ref = t.getref();
    const Test ct(s);
    auto cref = ct.getref();
    ct.getref() = "c++";
    auto p = ct.getptr();
    *p = "java";
    cout << ct.get_str();
    // auto self = ct.get_self();
}