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

int maxNum, orderCnt;
void bt(vector<int> &bag, vector<vector<int>> &orders, int startIndex) 
{
    if (startIndex == orders.size()) {
        if (orderCnt > maxNum)
            maxNum = orderCnt;
        return;
    }
    for (int i = startIndex; i < orders.size(); ++i) {
        int o1 = orders[i][0], o2 = orders[i][1];
        if (bag[o1] == 1 && bag[o2] == 1) {
            bag[o1] = 0;
            bag[o2] = 0;
            ++orderCnt;
            bt(bag, orders, i + 1);
            --orderCnt;
            bag[o1] = 1;
            bag[o2] = 1;
        }
        else {
            if (orderCnt > maxNum)
                maxNum = orderCnt;
        }
    }
    
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> orders(n, vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        cin >> orders[i][0] >> orders[i][1];
    }
    // m为背包容量
    // n个客人即为物品
    maxNum = 0, orderCnt = 0;
    vector<int> bag(m, 1);
    bt(bag, orders, 0);
    cout << maxNum;
}