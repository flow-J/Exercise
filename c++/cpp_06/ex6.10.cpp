#include <iostream>

int swap(int foo1, int foo2)
{
    int *temp = &foo1;
    foo1 = foo2;
    foo2 = *temp;
    std::cout << foo1 << " " << foo2;
}

int main()
{
    int fo1 = 1, fo2 = 2;
    swap(fo1,fo2);
}
