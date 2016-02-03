#include <iostream>

size_t count()
{
    static size_t foo = 0;
    return foo++;
}

int main()
{
    for (int i = 0; i < 10;++i)
        std::cout << count() << std::endl;

    return 0;
}
