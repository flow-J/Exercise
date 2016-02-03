#include <iostream>

template <typename Arr>
void print(Arr const& arr)
{
    for (auto const& f : arr)
        std::cout << f << std::endl;
}

int main()
{
    int foo[100] = { 1, 2, 3, 4, 5};
    print(foo);
}
