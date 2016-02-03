#include <iostream>

template <typename T,unsigned size>
T* begin(const T(&arr)[size])
{
    return arr;
}

template <typename T, unsigned size>
T* end(const T (&arr)[size])
{
    return arr + size;
}

int main()
{
    std::string s[] = {"ssss", "ss", "ss", "Ssssssssszz"};
    std::cout << *(begin(s)+1) << std::endl;
    std::cout << *(end(s) - 1) << std::endl;

    return 0;
}
