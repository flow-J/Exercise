#include <iostream>

size_t count_add(int n)
{
    static size_t count_add = 0;
    count_add += n;
    return count_add;
}

int main()
{
    std::cout << count_add(5) << std::endl;
}

