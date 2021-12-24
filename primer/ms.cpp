
#include <memory>
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>

class MyString {
public:
    MyString() : strs(nullptr), first_free(nullptr), cap(nullptr) {}
    MyString(const char []);
    MyString(const MyString &);
    MyString(const char *, const char *);
    // MyString(MyString &&) noexcept;
    ~MyString();
    MyString &operator=(const MyString &);
    bool operator<(const MyString &);
    friend std::ostream &operator<<(std::ostream &, const MyString &);
    size_t size() const { return first_free - strs; }
    size_t capacity() const { return cap - strs; }
    char *begin() const { return strs; }
    char *end() const { return first_free; }
    void reserve(size_t);
    void resize(size_t, const char);
    void push_back(const char);

    // some specific method
    MyString &substr(size_t, size_t);
    char &at(size_t); // 暂时无法实现重载[]
    // some pythonic method
    MyString &strip(const MyString &); // remove the space and line break at the begin and end of the string(default).
    MyString &slice(size_t, size_t); // like the str[:] in python
    std::vector<std::string> split(const MyString &);


private:
    static std::allocator<char> alloc;
    void chk_n_alloc() { if (size() == capacity())
            reallocate();
    }
    std::pair<char *, char *> alloc_n_copy(const char *, const char *); // 分配并复制指定指针范围内的字符
    void free();
    void reallocate(size_t n = 0);
    char *strs;
    char *first_free;
    char *cap;
};

inline
void MyString::push_back(const char c)
{
    chk_n_alloc();
    alloc.construct(first_free++, c);
}

inline
std::pair<char *, char *> MyString::alloc_n_copy(const char *b, const char *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

inline
void MyString::free()
{
    if (strs) {
        std::for_each(strs, first_free, [](char &c)
                      { alloc.destroy(&c); });
        alloc.deallocate(strs, cap - strs);
    }
}

inline
void MyString::reallocate(size_t n)
{
    if (!n)
        n = size() ? size() * 2 : 1;
    auto newdata = alloc.allocate(n);
    auto dest = newdata;
    auto elem = strs;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    strs = newdata;
    first_free = dest;
    cap = newdata + n;
}

inline
MyString::MyString(const char *s) : MyString() // 必须委托，否则三个指针为未定义的，reallocate不会成功
{
    // std::cout << "C-style string constructor" << std::endl;
    while (*s!='\0')
        push_back(*s++);
}

inline 
MyString::MyString(const MyString &ms)
{
    std::cout << "copy constructor" << std::endl;
    auto newdata = alloc_n_copy(ms.begin(), ms.end());
    strs = newdata.first;
    first_free = cap = newdata.second;
}
// inline
// MyString::MyString(MyString &&rhs) noexcept : strs(rhs.strs), first_free(rhs.first_free), cap(rhs.cap) 
// {
//     rhs.strs = rhs.first_free = rhs.cap = nullptr;
// }

inline
MyString::~MyString()
{
    free();
}

MyString& MyString::operator=(const MyString&rhs)
{
    std::cout << "copy operator=" << std::endl;
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    strs = newdata.first;
    first_free = cap = newdata.second;
    return *this;
} 

std::ostream &operator<<(std::ostream &os, const MyString &rhs)
{
    std::for_each(rhs.strs, rhs.first_free, [&os](char c)
                  { os << c; });
    return os;
}

inline
void MyString::reserve(size_t n)
{
    if (n > capacity())
        reallocate(n);
}

inline
void MyString::resize(size_t n, const char c = '\0')
{
    if (n < size())
        while (size() > n)
            alloc.destroy(--first_free);
    else if (n > size())
        while (size() < n)
            push_back(c);
}

inline 
MyString::MyString(const char *beg, const char *end)
{
    auto newdata = alloc_n_copy(beg, end);
    strs = newdata.first;
    first_free = cap = newdata.second;
}

// MyString& MyString::substr(size_t beg, size_t len)
// {
//     MyString *new_str = new MyString(strs + beg, beg + std::min(len, size()) + strs);
//     return *new_str;
// }

inline
char& MyString::at(size_t n)
{
    if (n < size())
        return *(strs + n);
    else
        throw std::out_of_range("at() out of range!\n");
}

inline
bool MyString::operator<(const MyString &rhs)
{
    if (size() == rhs.size()) {
        if (!size())
            return false;
        auto p1 = begin(), p2 = rhs.begin();
        while (p1 != end())
            if (*p1++ != *p2++)
                return *p1 < *p2;
        return false;
    }
    else
        return size() < rhs.size();
}

MyString &strip(const MyString &); // remove the space and line break at the begin and end of the string(default).
MyString &slice(size_t, size_t); // like the str[:] in python
std::vector<std::string> split(const MyString &);



int main()
{
    // std::vector<MyString> msvec;
    // MyString s("hello");
    // msvec.push_back(s);std::vector<String> vec;
    MyString s1("xxx");
    // MyString s2 = s1, s3;
    // s3 = s1;
    // msvec.push_back(s1);
    // msvec.push_back(s2);
    // msvec.push_back(MyString("2333"));
    std::cout << s1;
}