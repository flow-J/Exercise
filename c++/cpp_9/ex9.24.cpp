#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec;
    std::cout << vec.at(0);
    std::cout << vec.front();
    std::cout << *vec.begin();
    std::cout << vec[0];
    return 0;
}
