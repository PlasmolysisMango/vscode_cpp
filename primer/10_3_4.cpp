#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
using namespace std::placeholders;
using std::cout;
using std::endl;
using std::string;

bool check_size(const string &s, const string::size_type &size)
{
    return s.size() < size;
}

int main()
{
    std::vector<int> ivec;
    for (int i = 0; i < 24; ++i) {
        ivec.push_back(i * 2);
    }
    string s{"helloworld"};
    auto it = std::find_if(ivec.begin(), ivec.end(), std::bind(check_size, s, _1));
    cout << *it << endl;
}