#include <iostream>
#include <vector>
#include <string>

template <typename T>
auto sum(T lhs, T rhs)->decltype( lhs + rhs)
{
    return lhs + rhs;
}

int main()
{
    auto s = sum(122222222222222222222222222, 11111111111111111111111111);
    std::cout << s << std::endl;
}
