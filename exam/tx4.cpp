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

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param a ListNode类vector 指向每段碎片的开头
     * @return ListNode类
     */
    // 1拼接 2逆序
    bool merge(ListNode *p1, ListNode *p2) {
        ListNode *cur = p2;
        if (p1->val == p2->val)
            return true;
        while (cur->next)
        {
            if (p1->val == cur->next->val) {
                cur->next = p1;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
    ListNode* solve(vector<ListNode*>& a) {
        auto cpr = [](ListNode *lhs, ListNode *rhs)
        { return lhs->val < rhs->val; };
        sort(a.begin(), a.end());
        ListNode *beg = nullptr;
        for (int i = 0; i < a.size(); ++i) {
            for (int j = i + 1; j < a.size(); ++j) {
                if (merge(a[i], a[j])) {
                    if (!beg) {
                        beg = a[i];
                    }
                    break;
                }
            }
        }
        ListNode *last = a[a.size() - 1], *first = a[0];
        merge(last, first);
        // return beg;
        ListNode *pre = beg;
        ListNode *cur;
        ListNode *minnode = beg;
        int minval = beg->val;
        while (true) {
            ListNode *cur = pre->next;
            if (cur->val < minval) {
                minval = cur->val;
                minnode = pre;
            }
            pre = pre->next;
            if (cur == beg)
                break;
        }
        if (pre->val < cur->next->val) {

        }
        return cur;
    }
};

int main()
{
    ListNode *p1 = new ListNode(1);
    p1->next = new ListNode(2);
    p1->next->next = new ListNode(3);
    ListNode *p2 = new ListNode(2);
    p2->next = new ListNode(3);
    p2->next->next = new ListNode(4);
    ListNode *p3 = new ListNode(4);
    p3->next = new ListNode(1);
    Solution s;
    vector<ListNode *> a = {p1, p2, p3};
    ListNode *res = s.solve(a);
    while (res){
        cout << res->val;
        res = res->next;
    }
}