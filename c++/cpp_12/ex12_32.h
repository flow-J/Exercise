#ifndef CP5_ex12_32_h
#define CP5_ex12_32_h

#include "ex12_22.h"
using std::shared_ptr;

#include <iostream>
#include <fstream>
#include <map>
#include <set>


class QueryResult;
class TextQuery {
public:
    TextQuery(std::ifstream &);
    QueryResult query(const string&) const;
private:
    StrBlob file;
    std::map<string, shared_ptr<std::set<StrBlob::size_type>>> result;
};

class QueryResult {
public:
    friend std::ostream& print(std::ostream &, const QueryResult&);
public:
    QueryResult(const string &s, shared_ptr<std::set<StrBlob::size_type>> set, const StrBlob& f) : word(s), nos(set), file(f) { }
private:
    string word;
    shared_ptr<std::set<StrBlob::size_type>> nos;
    StrBlob file;
};

std::ostream& print(std::ostream &, const QueryResult&);

#endif


#include <sstream>
#include <algorithm>

TextQuery::TextQuery(std::ifstream &ifs)
{
    StrBlob::size_type lineNo{ 0 };
    for (string line; std::getline(ifs, line); ++lineNo)
    {
        file.push_back(line);
        std::istrings line_stream(line);
        for (string text, word; line_stream >> text; word.clear())
        {
            std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);

            auto &nos = result[word];
            if (!nos) nos.reset(new std::set<StrBlob::size_type>);
            nos->insert(lineNo);
        }
    }
}

QueryResult TextQuery::query(const string& str) const
{
    static shared_ptr<std::set<StrBlob::size_type>> nodate(new std::set<StrBlob::size_type>);
    auto found = result.find(str);
    if (found == result.end()) return QueryResult(str, nodate, file);
    else return QueryResult(str, found->second, file);
}

std::ostream& print(std::ostream &out, const QueryREsult& qr)
{
    out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times " : " time") << std::endl;
    for (auto i : *qr.nos)
    {
        ConstStrBlobPtr p(qr.file, i);
        out << "\t(line" << i+1 << ") " << p.deref() << std::endl;
    }

    return out;
}
