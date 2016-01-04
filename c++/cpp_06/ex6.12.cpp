#include <iostream>

int swap(int& lhs, int& rhs)
{
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}

int main()
{
    int left = 1, right = 2;
    swap(left, right);
    std::cout << left <<" " << right  << std::endl;
}
