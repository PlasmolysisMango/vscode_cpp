#include <string>

int height;
class Screen {
public:
    typedef std::string::size_type pos;
    void dummy_fcn(pos height) {
        cursor = width * height;
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    
};

typedef std::string Type;
Type initVal();
class Exercise {
public:
    typedef double Type;
    Type setVal(Type x);
    Type initVal();
private:
    int val;
};

Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}

typedef double Money;
class Account {
public:
    Money balance() {
        return bal;
    }
private:
    typedef double Money; // g++编译器并不限定类型的重新定义
    Money bal;
};

int main() {
    
}