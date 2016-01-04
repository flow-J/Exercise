#include <iostream>

using std::cout;
using std::endl;
using std::begin;
using std::end;
int main()
{
    int ia[3][4] = {
        { 0, 0, 0, 0},
        { 1, 1, 1, 1},
        { 2, 2, 2, 2}
    };

    for (auto p = begin(ia); p != end(ia); ++p)
    {
        for (auto q = begin(*p); q != end(*p); ++q)
            cout << *q << ' ';
        cout << endl;
    }
}
