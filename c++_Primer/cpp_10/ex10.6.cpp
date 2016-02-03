#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8};
    std::fill_n(vec.begin(),vec.size(), 0);

    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}
