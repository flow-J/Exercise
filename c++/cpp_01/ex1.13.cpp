#include <iostream>
int main()
{
    int sum = 0;
    for(int foo = 50; foo <= 100; foo++)
        sum += foo;
    std::cout << sum << std::endl;
    
    for(int i = 10; i >= 0;i--)
        std::cout << i << " " << std::endl;

    int big = 0, small = 0;
    std::cout << "Enter two integers:";
    std::cin >> big >> small;

    if(big < small)
    {
        int tmp = small;
        small = big;
        big = tmp;
    }

    for(;small <= big;small++)
        std::cout << small << " ";
    
    std::cout << std::endl;

    return 0;
}
