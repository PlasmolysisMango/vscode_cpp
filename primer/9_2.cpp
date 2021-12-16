#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>

using namespace std;

vector<int> vec1;
vector<int> vec2(vec1);
vector<int> vec3 = {1, 2, 3};
vector<int> vec4(vec3.cbegin(), vec3.cend());
vector<int> vec5(10);
vector<int> vec6(10, 3);

list<int> lst1{1, 2, 3};
vector<double> vec7(lst1.cbegin(), lst1.cend());

list<const char *> oldstyle = {"hell0", "world"};
vector<string> newstring{"233"};

int main()
{
    newstring.assign(oldstyle.cbegin(), oldstyle.cend());
    vec7 = {0.2, 0.1};
    for (const auto &i : newstring) {
        cout << i << " ";
    }
}