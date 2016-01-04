#include <iostream>
int main()
{
    int a = 0, b = 1;
    int *p1 = &a, *p2 = p1;

    std::cout << a << " " << b  << " "
        << *p1 << " " << *p2 << std::endl;

    p1 = &b;
    *p2 = b;
    
    std::cout << a << " " << b << " "
        << *p1 << " " << *p2 << std::endl;

    return 0;
}
