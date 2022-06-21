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

using namespace std;

string encr(const string &s) 
{
    // string res;
    // int size = s.size();
    // for (int i = 0; i < size; ++i) {
    //     int index = (s.size()+1) / 2 - 1;
    //     if (index < 0)
    //         index = 0;
    //     res += s[index];
    //     s.erase(s.begin() + index);
    // }
    // return res;
    string res(s.size(), '0');
    int left = (s.size()+1) / 2 - 1, right = (s.size()+2) / 2 - 1;
    for (int i = 0; i < s.size(); ) {
        if (left == right) {
            res[i] = s[left];
            ++i;
        }
        else {
            res[i] = s[left];
            res[i+1] = s[right];
            i += 2;
        }
        --left;
        ++right;
    }
    return res;
}

string decr(const string &s) 
{
    string res(s.size(), '0');
    int left = (s.size()+1) / 2 - 1, right = (s.size()+2) / 2 - 1;
    for (int i = 0; i < s.size(); ) {
        if (left == right) {
            res[left] = s[i];
            ++i;
        }
        else {
            res[left] = s[i];
            res[right] = s[i + 1];
            i += 2;
        }
        --left;
        ++right;
    }
    return res;
}

int main() 
{
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    string res;
    if (t == 1)
        res = encr(s);
    else
        res = decr(s);
    cout << res;
}