#ifndef _TEXTQUERY_H
#define _TEXTQUERY_H

#include <fstream>
using std::ifstream;

#include <memory>
using std::shared_ptr;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <map>
using std::map;

#include <set>
using std::set;

class QueryResult;

class TextQuery
{
public:
    typedef vector<string>::size_type line_no;

    TextQuery(ifstream&);
    QueryResult query(const string&) const;

private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;

    shared_ptr<vector<string>> handlePunct(const string&);
};

#endif

#include "queryResult.h"

#include <sstream>
using std::istringstream;

TextQuery::TextQuery(ifstream& is) :file(new vector<string>)
{
        using std::getline;

        string text;
    while (getline(is, text))
    {
        file->push_back(text);
            int n = file->size() - 1;
            istringstream line(text);
        string word;
        while (line >> word)
        {
            auto p = handlePunct(word);
            for (auto w : *p)
            {
                auto &lines = wm[w];
                if (!lines)
                    lines.reset(new set<line_no>);
                lines->insert(n);
            }
        }
    }

}


QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);

    auto loc = wm.find(sought);
    if(loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

shared_ptr<vector<string>> TextQuery::handlePunct(const string &s)
{
    shared_prt<vector<string>> p = make_shared<vector<string>>();
    size_t first = 0, index = 0;
    while(index != s.size())
    {
        if (ispunct(s[index]))
        {
            string word = s.substr(first, index - first);
            if (!word.empty())
                p->push_back(word);
            p->push_back(s.substr(index, 1));
            ++index;
            first = index;
        }
        else
            ++index;
    }
    string trail = s.substr(first);
    if (!trail.empty())
        p->push_back(trail);

    return p;
}
