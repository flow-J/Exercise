#include <iostream>
#include <map>
#include <string>
#include <typeinfo>

int main()
{
    std::map<int, std::string> m = { { 1, "ss" }, {2, "sz"} };
    using KeyType = std::map<int, std::string>::key_type;

    std::cout << "type to subscript: " << typeid(KeyType).name() << std::endl;
    std::cout << "returned from the subscript operator: " << typeid(decltype(m[1])).name() << std::endl;

    return 0;
}
