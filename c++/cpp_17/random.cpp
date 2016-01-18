#include <iostream>
#include <random>
#include <vector>

using namespace std;
/*
vector<unsigned> bad_randVec()
{
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0,9);
    vector<unsigned> ret;
    for (size_t i = 0; i < 100; ++i)
        ret.push_back(u(e));
    return ret;
}
*/

vector<unsigned> good_randVec()
{
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(0,9);
    vector<unsigned> ret;
    for (size_t i = 0; i < 100; ++i)
        ret.push_back(u(e));
    return ret;
}


int main()
{
 /*   default_random_engine e;
    for (size_t i = 0; i < 10; ++i)
        cout << e() << " ";
    cout << endl;
*/
    vector<unsigned> v1(good_randVec());
    vector<unsigned> v2(good_randVec());
    cout << ((v1 == v2) ? "equla" : "not equal") << endl;
}
