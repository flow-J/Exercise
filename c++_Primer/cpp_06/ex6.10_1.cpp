#include <iostream>

int swap(int* lhs, int* rhs)
{
    int temp;
    temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

int main()
{
    int i = 1, j = 2;
    swap(&i, &j);
    std::cout << i << " " << j << std::endl;
}
