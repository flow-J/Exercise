#ifndef _ORQUERY_H
#define _ORQUERY_H

#include <memory>
using std::shared_ptr;

#include "query.h"
#include "binaryquery.h"

class QueryResult;
class TextQuery;

class OrQuery :public BinaryQuery
{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "|"){ }
    QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif

#include "queryResult.h"
#include "textquery.h"

QueryResult
OrQuery::eval(const TextQuery &text) const
{
    auto right = rhs.eval(text);
    auto left = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QuertResult(rep(), ret_lines, left.get_file());
}
