#include <iostream>
#include <string>
#include <vector>

auto sum_for_int(std::vector<std::string> const& v)
{
    int sum = 0;
    for (auto const& s : v)
        sum += std::stol(s);
    return sum;
}

auto sum_for_float(std::vector<std::string> const& v)
{
    float sum = 0.0;
    for (auto const& s : v)
        sum += std::stof(s);
    return sum;
}

int main()
{
    std::vector<std::string> v = {"1", "2", "3", "4.5"};
    std::cout << sum_for_int(v) << std::endl;
    std::cout << sum_for_float(v) << std::endl;

    return 0;
}
