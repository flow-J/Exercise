#include <iostream>

template <typename T>
auto compare(T &v1, T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return  1;
    return 0;
}


int main()
{
    auto v1 = 1, v2 = 2;
    auto ans = compare(v1, v2);
    std::cout << ans << std::endl;
}
