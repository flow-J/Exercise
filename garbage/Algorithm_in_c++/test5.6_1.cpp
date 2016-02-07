#include <iostream>

auto max(auto a[], int l, int r)
{
    if (l == r) return a[l];
    int m = (l+r) / 2;
    auto u = max(a, l, m);
    auto v = max(a, m+1, r);
    if (u > v) return u; else return v;
}
