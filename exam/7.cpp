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

const int N = 1e5 + 10;
int snext[N];

void getNext(const string &t)
{
    memset(snext, -1, sizeof(snext));
    int j = -1;
    snext[0] = j;
    for (int i = 1; i < t.size(); ++i) {
        while (j >= 0 && t[i] != t[j+1])
            j = snext[j];
        if (t[i] == t[j+1])
            ++j;
        snext[i] = j;
    }
}

struct node {
    int left;
    int right;
    bool operator < (const node &rhs) {
        if (right == rhs.right)
            return left < rhs.left;
        return right < rhs.right;
    }
};

vector<node> nvec;
void kmp(const string &s, const string &t) 
{
    getNext(t);
    int j = -1;
    for (int i = 0; i < s.size(); ++i) {
        while (j >= 0 && s[i] != t[j+1])
            j = snext[j];
        if (s[i] == t[j+1])
            ++j;
        if (j == t.size()-1) {
            node tmp;
            tmp.left = i - j;
            tmp.right = i;
            nvec.push_back(tmp);
        }
    }
}

int n;
int main()
{
    cin >> n;
    vector<string> svec(n);
    for (int i = 0; i < n; ++i) {
        cin >> svec[i];
    }
    string s;
    cin >> s;
    for (const auto t : svec) {
        kmp(s, t);
    }
    sort(nvec.begin(), nvec.end());
    int last = -1;
    int cnt = 0;
    for (auto n : nvec) {
        if (n.left > last) {
            ++cnt;
            last = n.right;
        }
    }
    cout << cnt;
}