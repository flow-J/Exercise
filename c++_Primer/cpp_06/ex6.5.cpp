#include <iostream>

int abs(int i)
{
    return i > 0 ?  i : -i;
}

int main()
{
    std::cout << abs(-5) << std::endl;
}


