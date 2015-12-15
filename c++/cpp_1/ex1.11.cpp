#include <iostream>
int main()
{   
    int big = 0, small = 0;
    std::cout << "Enter two integers:";
    std::cin >> big >> small;

    if(small > big)
    {
        int tmp = small;
        small = big;
        big = tmp;
    }

    while(small <= big)
    {
        std::cout << small << " ";
        small++;
    }

    std::cout << std::endl;
    return 0;    
}
