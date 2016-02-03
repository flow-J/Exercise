#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;

bool str_subrange(const string &str1, const string &str2)
{
    if (str1.size() == str2.size()) 
        return str1 == str2;

    auto size = (str1.size() < str2.size()) //return the small one
                    ? str1.size() : str2.size();

    for (decltype(size) i = 0; i != size; ++i)
    {
        if (str1[i] != str2[i])
            return ;
    }

}

int main()
{
    string str1 = "abc" , str2 = "cba";
    str_subrange(str1, str2);
}
