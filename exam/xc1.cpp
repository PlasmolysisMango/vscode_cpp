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

int main()
{
    int n;
    cin >> n;
    int size = 4 * n;
    string line(size, '.');
    for (int i = 0; i < n; ++i) {
        line[i] = line[size - 1 - i] = '*';
    }
    // int right = size / 2, left = right - 1;
    for (int i = 0; i < size; ++i) {
        if (i < size - n) {
            cout << line << endl;
        }
        else {
            string tmp(size, '.');
            int len = i - (size - n) + 1;
            int left = len, right = size - 1 - len;
            for (int i = 0; i < n; ++i) {
                tmp[left + i] = tmp[right - i] = '*';
            }
            cout << tmp << endl;
        }
    }
}