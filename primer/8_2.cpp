#include <fstream>
#include <string>
#include <iostream>
using std::ifstream;
using std::ofstream;
using std::string;

string ifile("weight1.txt");
ifstream in(ifile);
ofstream out;

int main() {
    string s;
    int n;
    in >> s >> n;
    in.close();
    std::cout << s << " " << n << std::endl;

}
