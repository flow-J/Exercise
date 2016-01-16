#include <iostream>
#include <vector>
#include <cstring>

template<typename T>
std::size_t count(std::vector<T> const& vec, value)
{
    auto count = 0u;
    for(auto const& elem : vec)
        if(value == elem) ++count;
    return count;
}

template<>
std::size_t count (std::vector<const char*> const& vec, const char* value)
{
    auto count = 0u;
    for(auto const& elem : vec)
        if(0 == strcmp(value, elem)) ++count;
    return count;
}
int main()
{

    std::vector<const char*> vcc = { "alan", "alan", "alan", "alan", "moophy" };
    std::cout << count(vcc, "alan") << std::endl;

    return 0;
}
