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

int main()
{
    int n;
    cin >> n;
    vector<int> ori_prices(n, 0);
    for (int i = 0; i < n; ++i) 
        cin >> ori_prices[i];
    vector<int> zk_prices(n, 0);
    for (int i = 0; i < n; ++i) 
        cin >> zk_prices[i];
    int m;
    cin >> m;
    vector<vector<int>> mj(m, vector<int>(2, 0)); // c d
    for (int i = 0; i < m; ++i) 
        cin >> mj[i][0];
    for (int i = 0; i < m; ++i) 
        cin >> mj[i][1];
    sort(mj.begin(), mj.end(), [](vector<int> &lhs, vector<int> &rhs) -> bool
         {if (lhs[0] == rhs[0]) return lhs[1] > rhs[1]; return lhs[0] > rhs[0]; });
    int ori_sum = 0, zk_sum = 0;
    for (int i = 0; i < n; ++i) {
        ori_sum += ori_prices[i];
        zk_sum += zk_prices[i];
        int mj_sum = ori_sum;
        for (int mj_index = 0; mj_index < m; ++mj_index) {
            if (mj[mj_index][0] <= ori_sum) {
                mj_sum = ori_sum - mj[mj_index][1];
                break;
            }
        }
        if (zk_sum < mj_sum)
            cout << "Z";
        else if (zk_sum > mj_sum)
            cout << "M";
        else
            cout << "B";
    }
    return 0;
}