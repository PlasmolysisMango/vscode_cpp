#include <iostream>
#include <fstream>
using namespace std;
#include <vector>
#include <string>

double get()
{
    vector<int> res, nums1{1, 2}, nums2{3, 4};
    auto it1 = nums1.begin(), it2 = nums2.begin();
    while (it1 != nums1.end() && it2 != nums2.end())
    {
        if (*it1 < *it2)
        {
            res.push_back(*it1);
            ++it1;
        }
        else
        {
            res.push_back(*it2);
            ++it2;
        }
    }
    res.insert(res.end(), it1, nums1.end());
    res.insert(res.end(), it2, nums2.end());
    if (res.size() % 2)
        return res[res.size() / 2];
    else
        return (res[res.size() / 2] + res[res.size() / 2 - 1]) / 2.0;
}

class Text {
public:
    Text(const ifstream &x);
    Text(const string &s);
};

int main()
{
    cout << get() << endl;
    ifstream infile("233.txt");
    Text t(infile);
    Text t2(ifstream(string("2333")));
    Text t3("2333");
    Text t4(string("2333"));
}