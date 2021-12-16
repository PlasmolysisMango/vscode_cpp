#include <iostream>
using std::cout;

class Aggre {
public:
    int a;
    int b;
    int add() const {
        return a + b;
    }
};

int main() {
    Aggre x{5, 2};
    cout << x.add();
}