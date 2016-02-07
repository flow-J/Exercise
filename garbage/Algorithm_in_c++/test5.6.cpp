#include <iostream>
#include <vector>

using namespace std;

auto max(auto value, beg = value.begin(), end = value.end())
{
    auto val = value.begin();
    if (beg == end) return beg;
    auto mid = beg + value.size() / 2;
    auto beg = max(val,beg,mid);
    auto end = max(val, mid+1, end);
    if (beg > end) return beg; else return end;

}
