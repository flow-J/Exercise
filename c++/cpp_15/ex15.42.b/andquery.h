#ifndef _ANDQUERY_H
#define _ANDQUERY_H

#include <memory>
using std::shared_ptr;

#include "query.h"
#include "binaryquery.h"

class QueryResult;
class TextQuery;

class AndQuery :public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "&"){ }
	QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

#endif


#include <algorithm>
using std::set_intersection;

#include <iterator>
using std::inserter;

#include "set"
using std::set;

#include "queryResult.h"
#include "textquery.h"
#include "query.h"


QueryResult
AndQuery::eval(const TextQuery& text) const
{
	auto left = lhs.eval(text);
	auto right = rhs.eval(text);

	auto ret_lines = make_shared<set<line_no>>();

	set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));

	return QueryResult(rep(), ret_lines, left.get_file());
}
