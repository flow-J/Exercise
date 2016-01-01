#include <iostream>
#include <string>

using std::istream;

istream& function(istream &is)
{
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}

int main()
{
    istream& is = function(std::cin);
    std::cout << is.rdstate() << std::endl;
    return 0;
}
