#include <iostream>
#include <random>

//template <typename T = std::size_t>
//T random(T min = T(0), T max = T(1));

template <typename T = std::size_t>
T random_ex512(T min, T max)
{
    T ret = T(0);
    for (T i = min; i != max + 1; ++i)
        ret += random();
    return ret;
}

template <typename T>
T random(T min, T max)
{
    static std::default_random_engine e;
    static std::uniform_int_distribution<T> ud(min, max);
    return ud(e);
}

int main()
{
    std::string s;
    while (std::cin >> s)
    {
        if (s == "q")
            break;
        else
            std::cout << random_ex512(1,6) << std::endl;
    }
}
