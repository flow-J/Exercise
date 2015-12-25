#ifndef CP5_ex_7_5_h
#define CP5_ex7_5_h

#include <string>

class Person
{
    std::string name;
    std::string address;

public:
    auto get_name() const -> std::string const& { return name; }
    auto get_addr() const -> std::string const& { return address; }
};

#endif
