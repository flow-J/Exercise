/*
#include <iostream>

int main()
{
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;
    int i = 10, i2 = 42;
    std::cout << i2 -i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;

    return 0;
}*/
/*
#include <iostream>

int reused = 42;

int main()
{
    int unique = 0;
    std::cout << reused << " " << unique << std::endl;
    int reused = 0;

    std::cout << reused << " " << unique << std::endl;
    std::cout << ::reused << " " << unique << std::endl;
    return 0;

}*/

#include <iostream>
int main()
{
    int i = 0;
    int *fuck = &i;
    std::cout << i << " " << *fuck << std::endl;

    *fuck = 12;
    int a = i;
    std::cout << i << " " << a <<" " << *fuck << std::endl;
}
