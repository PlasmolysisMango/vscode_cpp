#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
// #include "output_container.h"

using namespace std;

using p_si = pair<string, int>;

int main()
{
    vector<p_si> pvec;

    // p_si tmp;
    // while (cin >> tmp.first >> tmp.second) {
    //     pvec.push_back(tmp);
    // }

    // string word;
    // int n;
    // while (cin >> word >> n) {
    //     pvec.push_back(make_pair(word, n));
    // }

    // string word;
    // int n;
    // while (cin >> word >> n) {
    //     p_si tmp(word, n);
    //     pvec.push_back(tmp);
    // }

    // for (const auto &p : pvec) {
    //     cout << p.first << " " << p.second << endl;
    // }

    vector<int> ivec;
    map<vector<int>::iterator, int> vmap;
    map<list<int>::iterator, int> lmap;
    vmap[ivec.begin()] = 1;
    vmap[ivec.end()] = 2;

    list<int> ilist;
    lmap[ilist.begin()] = 3;
    lmap[ilist.end()] = 4; 
    // list未定义迭代器的 < 符号，因此无法作为map的key_type。但是该点在编译环节并未检查，只有添加元素的时候才会出现，哪怕只添加一个元素。
}