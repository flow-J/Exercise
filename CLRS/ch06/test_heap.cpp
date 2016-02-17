#include "heap.cpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};

    clrs::ch06::build_heap(v.begin(), v.end());
    for (auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}
