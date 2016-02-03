#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "queryResult.h"
#include "queryhistory.h"
#include "textquery.h"
#include "andquery.h"
#include "orquery.h"
#include "notquery.h"
#include "query.h"

int main()
{
    ifstream fin("test.txt");
    TextQuery text(fin);
    QueryHistory history;
    Query q0("Alice");
    Query q1("hair");
    Query q2("Daddy");

    history.add_query(q0);
    history.add_query(q1);
    history[0] = history[0] | q2;

    auto result = history[0].eval(text);
    print(cout, result);

    return 0;
}
