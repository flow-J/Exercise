#include <list>
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> vec1{ 1, 2, 3, 4, 5 };
    std::list<int> vec2{ 1, 2, 3, 4, 5};

    std::cout << (std::vector<int>(vec2.begin(), vec2.end()) == vec1 ? "true" : "false") << std::endl;
}
