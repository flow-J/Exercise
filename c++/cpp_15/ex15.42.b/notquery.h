#ifndef _NOTQUERY_H
#define _NOTQUERY_H

#include <memory>
using std::shared_ptr;

#include <string>
using std::string;

#include "query.h"
#include "query_base.h"

class QueryResult;
class TextQuery;

class NotQuery :public Query_base
{
	friend Query operator~(const Query&);
	//call Query's default copy constructor.
	NotQuery(const Query &q) :query(q){ }
	string rep() const{ return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery&) const;

	Query query;
};

inline Query operator~(const Query &operand)
{
	return shared_ptr<Query_base>(new NotQuery(operand));
}

#endif


#include "queryresult.h"
#include "textquery.h"
#include "query.h"


QueryResult
NotQuery::eval(const TextQuery &text) const
{
	auto result = query.eval(text);

	auto ret_lines = make_shared<set<line_no>>();

	auto beg = result.begin();
	auto end = result.end();

	auto sz = result.get_file()->size();
	for (size_t n = 0; n != sz; ++n)
	{
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else if (beg != end)
			++beg;
	}
	return QueryResult(rep(), ret_lines, result.get_file());
}
