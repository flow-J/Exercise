#include <iostream>

int fact(int i)
{
    return i > 1 ? i * fact(i - 1) : 1;
}

int main()
{
    int i = 0;
    std::cout << "enter a number:   ";
    std::cin >> i;
    std::cout << fact(i) << std::endl;
}
