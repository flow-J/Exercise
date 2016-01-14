#ifndef _WORDQUERY_H
#define _WORDQUERY_H

#include <string>
using std::string;

#include "query.base.h"
#include "queryResult.h"
#include "textquery.h"

class WordQuery:public Query_base
{
    friend class Query;
    WordQuery(const string &s) :query_word(s){ }
    QueryResult evla(const TextQuery &t) const{ return t.query(quer_word); }
    string rep() const { return query_word; }

    string query_word;

};

#endif
