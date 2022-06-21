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

unordered_set<string> umap;
vector<string> res;
void judge(const string &s)
{
    string cmd;
    if (s.size() < 6 || s.size() > 12)
        cmd = "illegal length";
    else {
        for (auto c: s) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                ;
            }
            else
            {
                cmd = "illegal charactor";
                break;
            }
        }
    }
    if (cmd.empty() && umap.find(s) != umap.end()) {
        cmd = "account existed";
    }
    if (cmd.empty()) {
        cmd = "registration complete";
        umap.insert(s);
    }
    res.push_back(cmd);
}

int n;
int main()
{
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        judge(s);
    }
    for(auto x : res) {
        cout << x << endl;
    }
}