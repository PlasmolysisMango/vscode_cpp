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

int N;

string s1, s2;

int main()
{
    cin >> N;
    cin.get();
    getline(cin, s1);
    getline(cin, s2);
    int alpha[26] = {0};
    for (int i = 0; i < N; ++i)
    {
        alpha[s1[i] - 'a']++;
        alpha[s2[i] - 'a']--;
    }
    // a g (3, 7)
    // b e (1, 5)
    vector<int> si1, si2;
    for (int i = 0; i < 26; ++i) {
        if (alpha[i] > 0) {
            for (int j = 0; j < alpha[i]; ++j)
                si1.push_back(i);
        }
        else if (alpha[i] < 0) {
            for (int j = 0; j < -alpha[i]; ++j)
                si2.push_back(i);
        }
    }
    int res = 0;
    for (int i = 0; i < si1.size(); ++i) {
        res += abs(si1[i] - si2[i]);
    }
    cout << res;
}