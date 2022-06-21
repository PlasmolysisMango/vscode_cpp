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

struct Item {
    int position = 0;
    int rate = 0;
    int dmg = 0;
    Item(){}
    Item(int _pos, int _rate, int _dmg): position(_pos), rate(_rate), dmg(_dmg) {}
    bool operator < (const Item &rhs) {
        if (rate == rhs.rate) {
            return dmg > rhs.dmg;
        }
        return rate < rhs.rate;
    }
};

vector<vector<Item>> allpos_items;
int max_dmg = -1;
int cur_rate = 0;
int cur_dmg = 0;
// vector<Item> selected;
void bt(int pos, int item_idx) {
    if (cur_rate >= 100 && pos == 6) {
        max_dmg = max(max_dmg, cur_dmg);
    }
    if (pos > 5) {
        return;
    }
    vector<Item> &ivec = allpos_items[pos];
    int size = ivec.size();
    for (int i = item_idx; i < size; ++i) {
        if (i != item_idx && ivec[i].rate == ivec[i-1].rate) {
            continue;
        }
        Item &cur_item = ivec[i];
        cur_rate += cur_item.rate;
        cur_dmg += cur_item.dmg;
        // selected.push_back(cur_item);
        bt(pos + 1, 0);
        // selected.pop_back();
        cur_rate -= cur_item.rate;
        cur_dmg -= cur_item.dmg;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        allpos_items.clear();
        allpos_items = vector<vector<Item>>(6);
        max_dmg = -1;
        cur_rate = cur_dmg = 0;
        int n;
        cin >> n;
        while (n--) {
            int p, c, d;
            cin >> p >> c >> d;
            Item tmp(p, c, d);
            allpos_items[p - 1].push_back(tmp);
        }
        for (auto &ivec : allpos_items) {
            sort(ivec.begin(), ivec.end());
        }
        bt(0, 0);
        if (max_dmg == -1) {
            cout << "TAT";
        }
        else {
            cout << max_dmg;
        }
        cout << endl;
    }
}


