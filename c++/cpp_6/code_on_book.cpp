#include <iostream>
#include <string>

using std::string;

/*
size_t count_calls()
{
    static size_t ctr = 0;
    return ++ctr;
}

int main()
{
    for (size_t i = 0; i != 10; ++i)
        std::cout << count_calls() << std::endl;
}
*/


string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}

int main()
{
    int ctr = 0;
    string s = "abcedfnnnndnd";
    std::cout << find_char(s, 'n', ctr) <<  std::endl;
}
