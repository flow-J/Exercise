#include <iostream>
#include <vector>
#include <string>

class Bar{ };

Bar operator +(Bar lhs, int)
{
    return lhs;
}

template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
    return *beg;
}

int main()
{
    std::vector<Bar> v;
    v.push_back(Bar());
    Bar b = fcn3(v.begin(), v.end());
}
