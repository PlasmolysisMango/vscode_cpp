#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    static int s_uni;
    int no;
    string name;

public:
    Employee(const string &s = string()): no(s_uni++), name(s) {}
    Employee(const Employee &r) : no(s_uni++), name(r.name) {}
    void print() { cout << no << " " << name << endl; }
};

int Employee::s_uni = 0;

int main()
{
    Employee a("jack");
    a.print();
    Employee b = a;
    b.print();
}