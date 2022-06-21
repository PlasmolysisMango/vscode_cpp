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

using namespace std;

int a, b, c, d;
int main()
{
    cin >> a >> b >> c >> d; // a坦克 b碉堡生命 c每个碉堡摧毁坦克 d碉堡数量
    int cnt = 0;
    int remain_life = 0;
    while (a >= remain_life && d > 0) {
        int desnum;
        int avi_tank;
        if (remain_life == b) {
            desnum = 0;
            avi_tank = a;
        }
        else {
            desnum = 1;
            avi_tank = a - remain_life; // 剩余可开火坦克
        }
        desnum += avi_tank / b; // 摧毁碉堡数量
        avi_tank = avi_tank % b; // 剩余可开火坦克
        remain_life = b - avi_tank; // 碉堡剩余生命值
        d -= desnum;
        a -= d * c;
        ++cnt;
    }
    if (d > 0)
        cout << -1;
    else
        cout << cnt;
}