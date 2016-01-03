#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::vector;
using std::count_if;
using std::string;

std::size_t bigerThan6(vector<string> const& v)
{
    return count_if(v.cbegin(), v.cend(),
            [](string const& s) {return s.size() > 6; });
}

int main()
{/*
    std::count_if(v.begin(),v.end(),
            [&v]() mutable {return v.size() > 6 ? v : continue})
            */
    vector<string> v{ "alan", "moophy", "1234567", "1234567", "1234567", "1234567"};
    std::cout << "ex10.20: " << bigerThan6(v) << std::endl;


    int i = 7;
    auto check_and_decrement = [&i](){ return --i ? false : true; };
    std::cout << "ex10.21: ";
    while (!check_and_decrement())
        std::cout << i << " ";
    std::cout << i << std::endl;

    return 0;
}
