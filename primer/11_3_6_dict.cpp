#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
// #include "output_container.h"

using namespace std;

map<string, string> get_dict(ifstream &dictfile)
{
    map<string, string> dict;
    string key, value;
    while (dictfile >> key && getline(dictfile, value)) {
        if (value.size() > 1) {
            dict[key] = value.substr(1);
        }
        else
            throw runtime_error("no rules for" + key);
    }
    return dict;
}

const string &transform(const string &s, const map<string, string> &dict)
{
    auto it = dict.find(s);
    if (it != dict.cend())
        return it->second;
    else
        return s;
}

void print_transform(ifstream &infile, ifstream &dictfile)
{
    map<string, string> dict = get_dict(dictfile);
    string text;
    while (getline(infile, text)) {
        istringstream str_in(text);
        string word;
        bool flag = false;
        while (str_in >> word) {
            if (!flag)
                flag = true;
            else
                cout << " ";
            cout << transform(word, dict);
        }
        cout << endl;
    }
}

int main() 
{
    ifstream infile("in.txt"), dictfile("dict.txt");
    if (infile.good() && dictfile.good())
        print_transform(infile, dictfile);
    else
        throw runtime_error("files error!");
}