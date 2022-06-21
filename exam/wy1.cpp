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

int single, aoe, mo1, mo2;

int main()
{
    int cnt = 0;
    cin >> mo1 >> mo2 >> single >> aoe;
    if (aoe >= single) {
        while (mo1 > 0 || mo2 > 0) {
            mo1 -= aoe;
            mo2 -= aoe;
            ++cnt;
        }
    }
    else if (aoe * 2 <= aoe){
        while (mo1 > 0) {
            mo1 -= single;
            ++cnt;
        }
        while (mo2 > 0) {
            mo2 -= single;
            ++cnt;
        }
    }
    else {
        while (mo1 > 0 && mo2 > 0) {
            mo1 -= aoe;
            mo2 -= aoe;
            ++cnt;
        }
        while (mo1 > 0) {
            mo1 -= single;
            ++cnt;
        }
        while (mo2 > 0) {
            mo2 -= single;
            ++cnt;
        }
    }
    cout << cnt << endl;
}