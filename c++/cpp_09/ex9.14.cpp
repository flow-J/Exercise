#include <iostream>
#include <string>
#include <vector>
#include <list>

int main()
{
    std::list<const char*> foo{"hello", " ","world"};
    std::vector<std::string> foo1;
    foo1.assign(foo.cbegin(), foo.cend());
    for (auto ptr : foo1)
        std::cout << ptr;
    std::cout << std::endl;
    return 0;
}
