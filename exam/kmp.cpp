#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> getNext(const string &t) 
{
    int j = -1;
    vector<int> snext(t.size(), 0);
    snext[0] = j;
    for (int i = 1; i < t.size(); ++i) {
        while (j >= 0 && t[j+1] != t[i])
            j = snext[j];
        if (t[j+1] == t[i])
            ++j;
        snext[i] = j;
    }
    return std::move(snext);
}

int kmp(const string &s, const string &t) {
    vector<int> snext = getNext(t);
    int j = -1;
    for (int i = 0; i < s.size(); ++i) {
        while (j >= 0 && s[i] != t[j+1])
            j = snext[j];
        if (s[i] == t[j+1])
            j++;
        if (j == t.size()-1)
            return i - j;
    }
    return -1;
}

int main() 
{
    cout << kmp("hello world", "world");
}