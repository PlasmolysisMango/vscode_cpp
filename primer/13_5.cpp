#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <algorithm>
#include <vector>

class StrVec {
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);
    StrVec(std::initializer_list<std::string> li);
    StrVec &operator=(const StrVec &);
    ~StrVec();
    void push_back(const std::string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    void reserve(size_t n);
    void resize(size_t n, const std::string &t = "");
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc() { if (size() == capacity())
            reallocate();
    }
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free();
    void reallocate();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string *, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::free()
{
    if (elements) {
        // for (auto p = first_free; p != elements;)
        //     alloc.destroy(--p);
        std::for_each(elements, first_free, [](std::string &s)
                      { alloc.destroy(&s); });
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    std::cout << "copy constructor" << std::endl;
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    std::cout << "copy operator=" << std::endl;
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reserve(size_t n)
{
    if (n <= capacity())
        return;
    auto newcapacity = n;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

inline void StrVec::resize(size_t n, const std::string &t)
{
    if (n < size())
        while (size() > n)
            alloc.destroy(--first_free);
    else if (n > size())
        while (size() < n)
            push_back(t);
}

inline StrVec::StrVec(std::initializer_list<std::string> il)
{
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

int main()
{
    // StrVec svec{"1220, ", "wordl"};
    // for (auto it = svec.begin(); it != svec.end(); ++it)
    //     std::cout << *it << " ";
    std::vector<StrVec> svec;
    StrVec s1{"2333"};
    StrVec s2 = s1;
    svec.push_back(s1);
    svec.push_back(s2);
}