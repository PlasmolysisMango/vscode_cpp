#include <string>
#include <iostream>

class Sales_data {
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), unit_sold(n), revenue(p * n) {}
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(std::istream &);
    std::string isbn() const { return bookNo; }
    Sales_data &conbine(const Sales_data &);

private:
    double avg_price() const
    {
        return unit_sold ? revenue / unit_sold : 0;
        }
        std::string bookNo;
        unsigned unit_sold = 0;
        double revenue = 0.0;
};

Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);