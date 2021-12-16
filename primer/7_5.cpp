#include <iostream>
#include <string>

class Sales_data {
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
public:
    // Sales_data() = default; 委托构造函数
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), unit_sold(n), revenue(p * n) {
        std::cout << "ConstructFunc1" << std::endl;
        }
    Sales_data(): Sales_data("", 0, 0) { 
        std::cout << "ConstructFunc2" << std::endl;
    }
    Sales_data(const std::string &s) : Sales_data(s, 0, 0) {
        std::cout << "ConstructFunc3" << std::endl;
    }
    Sales_data(std::istream &is): Sales_data() {
        std::cout << "ConstructFunc4" << std::endl;
    }
    std::string isbn() const { return bookNo; }
    Sales_data &conbine(const Sales_data &);

private:
    std::string bookNo;
    unsigned unit_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);



int main() {
    Sales_data(std::cin);
}