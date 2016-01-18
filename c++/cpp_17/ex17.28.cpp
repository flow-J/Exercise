#include <random>
#include <vector>
#include <iostream>

using namespace std;

vector<unsigned> randVec()
{
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0, 100);
    vector<unsigned> ret;
    for (int i = 0; i < 100; ++i)
        ret.push_back(u(e));
    return ret;
}


template <typename T>
vector<unsigned> randVec(T const& t)
{
    default_random_engine e(t);
    vector<unsigned> ret;
    for (int i = 0; i < 1; i++)
        ret.push_back(t);
    return ret;
}


int main()
{
    vector<unsigned> v1(randVec(5));

    for (auto i : v1)
        cout << i << endl;
}
