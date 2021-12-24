#include <iostream>
#include <vector>
#include <string>

template <typename T>
void print(const T &cta) 
{
    for (typename T::size_type i = 0; i != cta.size(); ++i) {
        std::cout << cta[i] << " ";
    }
    std::cout << std::endl;
    for (typename T::iterator beg = cta.begin(); beg != cta.end(); ++beg) {
        std::cout << *beg << " ";
    }
}

int main()
{
    std::vector<std::string> svec{"hello", "world"};
    // auto beg = svec.begin();
    // auto sz = svec.size();
    print(svec);
}