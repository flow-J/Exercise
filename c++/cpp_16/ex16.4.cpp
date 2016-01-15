#include <iostream>
#include <vector>
namespace ch16
{
    template <typename T,typename Value> // T named iterator will be better;
    auto find(T first, T last,Value const& value)
    {
        for ( ; first != last && *first != value; ++first);
        return first;
    }
}

int main()
{
    std::vector<int> vec = { 1, 2, 3, 4, 5,6,7};
    auto ans = vec.cend() != ch16::find(vec.cbegin(), vec.cend(), 100);
    std::cout << (ans ? "found\n" : "not found\n") << std::endl;
}
