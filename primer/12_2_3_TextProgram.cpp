#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <memory>

// using namespace std;

class QueryResult;

class TextQuery
{
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery() = default;
    TextQuery(std::ifstream &infile);
    QueryResult query(const std::string &s) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream &infile) : file(new std::vector<std::string>)
{
    std::string line;
    while (std::getline(infile, line)) {
        file->push_back(line);
        line_no num = file->size() - 1;
        std::istringstream in_ss(line);
        std::string word;
        while (in_ss >> word) {
            word.erase(std::remove_if(
                word.begin(), word.end(), [](char c)
                { return ispunct(c); }), word.end());
            auto &set_ptr = wm[word];
            if (!set_ptr)
                set_ptr.reset(new std::set<line_no>);
            set_ptr->insert(num);
        }
    }
}

class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult&);
public:
    QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p, std::shared_ptr<std::vector<std::string>> f) : 
        sought(s), lines(p), file(f) {}
    std::set<TextQuery::line_no>::iterator begin() const { return lines->cbegin(); }
    std::set<TextQuery::line_no>::iterator end() const { return lines->cend(); }
    std::shared_ptr<std::vector<std::string>> getfile() const { return file; }

private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

QueryResult TextQuery::query(const std::string &sought) const
{
    static std::shared_ptr<std::set<TextQuery::line_no>> nodata(new std::set<TextQuery::line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " time(s)" << std::endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
    return os;
}

void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit" << std::endl;
        std::string s;
        if (!(std::cin >> s) || s == "q")
            break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

// int main()
// {
//     std::ifstream infile("text_container.txt");
//     runQueries(infile);
// }