#include <vector>
#include "merge_sort.cpp"
#include <iostream>

int main()
{
    auto ret = clrs::ch02::merge(std::vector<int> {1,2,3,4,5}, std::vector<int> { 2,3,41});
    clrs::ch02::merge_sort(ret);
    for (auto i : ret)
        std::cout << i << " ";
    std::cout << std::endl;
}
