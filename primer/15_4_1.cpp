#include <iostream>
#include <string>
#include <memory>
#include <set>

// using namespace std;

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price): bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Quote() = default;
    virtual Quote *clone() const & { return new Quote(*this); }
    virtual Quote *clone() const && { return new Quote(std::move(*this)); }

private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote: public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) : Disc_quote(book, price, qty, disc) {}
    double net_price(std::size_t) const override;
    Bulk_quote *clone() const & override { return new Bulk_quote(*this); }
    Bulk_quote *clone() const && override { return new Bulk_quote(std::move(*this)); }
};

double Bulk_quote::net_price(std::size_t n) const
{
    if (n > quantity)
        return price * quantity + price * (n - quantity) * (1 - discount);
    else
        return n * price;
}

class Basket {
public:
    void add_item(const Quote &sale) { items.insert(std::shared_ptr<Quote>(sale.clone())); }
    void add_item(const Quote &&sale) { items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }
    double total_receipt(std::ostream &) const;
private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
    {
        return rhs->isbn() < lhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

double Basket::total_receipt(std::ostream &os) const
{
    double sum(0.0);
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
        sum += print_total(std::cout, **iter, items.count(*iter));
    }
    os << "Total Sale: " << sum << std::endl;
    return sum;
}

int main()
{
    Quote A("c++", 24.3);
    Bulk_quote B("java", 35.1, 5, 0.8);
    Basket bsk;
    bsk.add_item(A);
    bsk.add_item(B);
    bsk.add_item(Bulk_quote("python", 20.0, 2, 0.9));
    bsk.total_receipt(std::cout);
}