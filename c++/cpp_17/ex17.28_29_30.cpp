#include <random>
#include <iostream>

using namespace std;

unsigned random_gen()
{
    static std::default_random_engine e;
    static std::uniform_int_distribution<unsigned> ud;
    return ud(e);
}


unsigned random_gen(unsigned seed)
{
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned> ud;
    return ud(e);
}

unsigned random_gen(unsigned seed, unsigned min, unsigned max)
{
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned> ud(min, max);
    return ud(e);
}

int main()
{
    std::string temp;
    while (std::cin >> temp)
        std::cout << std::hex << random_gen(19, 1, 10) << std::endl;
    return 0;
}


















































/*
vector<unsigned> randVec()
{
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0, 100);
    vector<unsigned> ret;
    for (int i = 0; i < 100; ++i)
        ret.push_back(u(e));
    return ret;
}


template <typename T>
vector<unsigned> randVec(T const& t)
{
    default_random_engine e(t);
    vector<unsigned> ret;
    for (int i = 0; i < 1; i++)
        ret.push_back(t);
    return ret;
}


int main()
{
    vector<unsigned> v1(randVec(5));

    for (auto i : v1)
        cout << i << endl;
}*/
