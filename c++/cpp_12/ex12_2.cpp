#include "ex12_2.h"
#include <iostream>

int main()
{
    const StrBlob csb{ "hello", "world", "flow"};
    StrBlob sb{ "hello", "world", "pezy" };

    std::cout << csb.front() << " " << csb.back() << std::endl;
    sb.back() = "flow";
    std::cout << sb.front() << " " << sb.back() << std::endl;
}
