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

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);

    // fetch the iterator to the matching element in the map<word, lines>.
    //std::map<std::string, std::shared_ptr<std::set<line_no>>>::const_iterator
    auto loc = wm.find(sought);
    if(loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

shared_ptr<vector<string>> TextQuery::handlePunct(const string &s)
{
	shared_ptr<vector<string>> p =
		make_shared<vector<string>>();
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

