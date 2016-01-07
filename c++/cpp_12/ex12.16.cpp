#include <iostream>
#include <string>
#include <memory>

using std::string;
using std::unique_ptr;

int main()
{
    unique_ptr<string> p1(new string("flow"));

    std::cout << *p1 << std::endl;
    p1.reset(nullptr);
}
