// 此练习为函数指针
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int getInt(int, int);

vector<decltype(getInt) (*)> funvec; // 必须显式书写（*）

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int main() {
    int a = 6, b = 3;
    funvec.push_back(add);
    funvec.push_back(subtract);
    funvec.push_back(&multiply); // 是否书写取地址符号不影响函数指针。不写也会转换为相应的格式。
    funvec.push_back(divide);
    for (decltype(add) *fun : funvec) {
        cout << fun(a, b) << endl;
    }
}