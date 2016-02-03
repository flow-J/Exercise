#include <iostream>
#include <vector>
#include <cstring>

// template
template<typename T>
<<<<<<< HEAD
std::size_t count(std::vector<T> const& vec,T value)
=======
std::size_t  count(std::vector<T> const& vec, T value) 
>>>>>>> 9df28e7042708fd7591a6c9e4d18b3da8eaa3235
{
    auto count = 0u;
    for(auto const& elem  : vec)
        if(value == elem) ++count;
    return count;
}

// template specialization
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
    // for ex16.63
    std::vector<double> vd = { 1.1, 1.1, 2.3, 4 };
    std::cout << count(vd, 1.1) << std::endl;
    
    // for ex16.64
    std::vector<const char*> vcc = { "alan", "alan", "alan", "alan", "moophy" };
    std::cout << count(vcc, "alan") << std::endl;

    return 0;
}
