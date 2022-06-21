#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == 1) {
            if (k == 1)
                return "0";
            else 
                return num;
        }
        int slow = 0, fast = 1;
        for (; fast < num.size() && k; fast++) {
            if (num[fast] <= num[fast-1]) {
                k--;
            }
            else {
                num[slow++] = num[fast-1];
            }
        }
        int beg = 0;
        if (k == 0) // 即删除完全
            while (fast <= num.size())
                num[slow++] = num[(fast++)-1];
        else
            beg += k;
        while (num[beg] == '0')
            beg++;
        return num.substr(beg, slow-beg);
    }
};

int main() 
{
    string s{"1432219"};
    int k = 3;
    Solution so;
    so.removeKdigits(s, k);
}