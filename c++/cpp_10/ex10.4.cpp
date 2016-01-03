#include <iostream>
#include <numeric>
#include <vector>

int main()
{
    std::vector<double> num = {1, 2, 3, 4, 5};
    std::cout << std::accumulate(num.cbegin(), num.cend(), 0)
        << std::endl;
} 
