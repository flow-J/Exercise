#include <iostream>

int puzzle(int N)
{
    if (N == 1) return 1;
    if (N % 2 == 0)
        return puzzle(N/2);
    else return puzzle(3*N+1);
}

int main()
{
    auto p = puzzle(6);
    std::cout << p << std::endl;
}
