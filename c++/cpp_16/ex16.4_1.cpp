
#include <iostream>
#include <vector>
#include <list>
#include <string>

namespace ch16
{
    template<typename Iterator, typename Value>
    auto find(Iterator first, Iterator last, Value const& value)
    {
        for (; first != last && *first != value; ++first);
        return first;
    }
}

int main()
{
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto is_in_vector = v.cend() != ch16::find(v.cbegin(), v.cend(), 5);
    std::cout << (is_in_vector ? "found\n" : "not found\n");

    std::list<std::string> l = { "aa", "bb", "cc", "dd", "ee", "ff", "gg" };
    auto is_in_list = l.cend() != ch16::find(l.cbegin(), l.cend(), "zz");
    std::cout << (is_in_list ? "found\n" : "not found\n");

    return 0;
}
