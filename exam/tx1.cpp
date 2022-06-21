#include <queue>
#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <memory>
#include <functional>
#include <cstring>   
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int n;

// struct snum {
//     string s;
//     snum(const string &tmp) {
//         auto n = tmp.find_first_not_of('0');
//         s = tmp.substr(n);
//     }
//     bool operator < (const snum &rhs) {

//     }
// };

int main() 
{
    vector<string> vec;
    cin >> n;
    int size = -1;
    for (int j = 0; j < n; ++j)
    {
        string tmp;
        cin >> tmp;
        if (size == -1) {
            size = tmp.size();
            vec.resize(size, string(n, '0'));
        }
        for (int i = 0; i < size; ++i)
        {
            vec[i][j] = tmp[i];
        }
    }
    sort(vec.begin(), vec.end());
    for (auto &s : vec)
    {
        auto n = s.find_first_not_of('0');
        cout << s.substr(n) << " ";
    }
}