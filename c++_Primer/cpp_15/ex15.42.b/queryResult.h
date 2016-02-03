#ifndef _QUERYRESULT_H
#define _QUERYRESULT_H

#include <iostream>
using std::ostream;

#include <memory>
using std::shared_ptr;

#include <set>
using std::set;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "textquery.h"

class QueryResult
{
    friend ostream& print(ostream&, const QueryResult&);

public:
    QueryResult(string s,
            shared_ptr<set<TextQuery::line_no>> 1,
            shared_ptr<vector<string>> f) :
        sought(s), lines(l), file(f){ }

    set<TextQuery::line_no>::iterator begin(){ return lines->begin(); }
    set<TextQuery::line_no>::iterator end(){ return lines->end(); }
    shared_ptr<vector<string>> get_file(){ return file; }

private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
    shared_ptr<vector<string>> file;
};

ostream&
print(ostream&, const QueryResult& qr)
{
    os << "The result of your query " << qr.sought << " is: \n";
    for (const auto &index: *qr.lines)
        os << "\t(line " << index + 1 << ")"
            << *(qr.file->begin() + index) << "\n";
    return os;
}

#endif


