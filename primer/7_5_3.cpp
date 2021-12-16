#include <vector>

class NoDefault {
public:
    NoDefault(int x): val(x) {}
private:
    int val;
};

class C {
public:
    C():param(2) {}
private:
    NoDefault param;
};

C c;

std::vector<C> vec(10);

int main() {

}