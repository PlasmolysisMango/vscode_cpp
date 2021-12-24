#include <iostream>
#include <string>

// using namespace std;

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price): bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double sales_price, 
               std::size_t qty, double disc) : Quote(book, sales_price), min_qty(qty), discount(disc) {}
    double net_price(std::size_t) const override;

private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt > min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

class NumLimit_quote : public Quote {
public:
    NumLimit_quote() = default;
    NumLimit_quote(const std::string &book, double p, std::size_t lmt_num, double disc) : 
                   Quote(book, p), limit_num(lmt_num), discount(disc) {}
    double net_price(std::size_t) const override;

private:
    std::size_t limit_num = 0;
    double discount = 0.0;
};

double NumLimit_quote::net_price(std::size_t cnt) const
{
    if (cnt <= limit_num)
        return cnt * price * (1 - discount);
    else
        return limit_num * price * (1 - discount) + (cnt - limit_num) * price;
}