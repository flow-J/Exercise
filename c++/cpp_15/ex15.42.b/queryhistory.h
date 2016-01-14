#ifndef _QUERYHISTORY_H
#define _QUERYHISTORY_H

#include <memory>
using std::shared_ptr;

#include <vector>
using std::vector;

#include "query.h"

class QueryHistory
{
public:
    Query &operator[](size_t n)
    {
        return *(query_vec[n]);
    }
    size_t add_query(const Query&);
private:
    vector<shared_ptr<Query>> query_vec;
};

#endif

using std::make_shared;

size_t QueryHistory::add_query(const Query &query)
{
    shared_ptr<Query> p = make_shared<Query>(query);
    query_vec.push_back(p);
    return query_vec.size() - 1;
}
