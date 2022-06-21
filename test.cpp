/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        istringstream is(s);
        char c;
        int res = 0;
        int flag = 0;
        while (is >> noskipws >> c) {
            cout << c;
            if (!flag) {
                if (c == '+')
                    flag = 1;
                else if (c == '-')
                    flag = -1;
                else if (isnum(c)) {
                    flag = 1;
                    res = c - '0';
                }
                else if (!isspace(c))
                    break;
            }
            else if (isnum(c)) {
                if (!res)
                    res = flag * (c - '0');
                else
                    res = check(res, c - '0');
                if (res == INT32_MIN || res == INT32_MAX)
                    break;
            }
            else
                break;
        }
        cout << endl;
        return res;
    }

    bool isnum(char c)
    {
        return c >= '0' && c <= '9';
    }

    int check(int res, int n)
    {
        if (res > 0) {
            if (INT32_MAX / res < 10 || INT32_MAX - 10 * res < n)
                return INT32_MAX;
        }
        else if (res < -1) {
            if (INT32_MIN / res < 10 || INT32_MIN - 10 * res > -n)
                return INT32_MIN;
        }
        return res >= 0 ? res * 10 + n : res * 10 - n;
    }
};

int main()
{
    Solution s;
    cout << s.myAtoi("    +0 123");
}
// @lc code=end

