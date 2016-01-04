#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec{ 1, 2, 3, 4, 5, 5, 5, 5};
    std::list<int> lst;
    std::unique_copy(vec.begin(), vec.end(), back_inserter(lst));

    for (auto i : lst)
        std::cout << i << " ";
    std::cout << std::endl;
}
