#include <iostream>

template<typename T, unsigned size>
constexpr unsigned getSize(const T(&)[size])
{
    return size;
}
