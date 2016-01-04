#include <iostream>
#include <string>

int main()
{
    std::string s = "word";
    std::cout << s + (s[s.size() - 1]  == 's' ? "" : "s") << std::endl;
}
