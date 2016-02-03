#include <iostream>

using std::cout;
template <typename T>
std::ostream &print(std::ostream &os, const T &t)
{
    return os << t;
}

template <typename T, typename ... Args>
std::ostream &print(std::ostream &os, const T &t, const Args&... rest)
{
    os << t << " ";
    return print(os, rest...);
}
int main()
{
    print(cout, 1, 2, 3) << std::endl;
    print(cout, 2, 2) << std::endl;
    print(cout, 1) << std::endl;
    print(cout, "string", 2) << std::endl;
}
