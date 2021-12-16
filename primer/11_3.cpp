#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
// #include "output_container.h"

using namespace std;

int main() 
{
    map<string, int> imap;
    auto pir = imap.insert({"233", 2});
    auto it = pir.first;
 
    map<string, vector<int>> vecmap;
    pair<map<string, vector<int>>::iterator, bool> par = vecmap.insert({"233", {1, 2, 3}});
}