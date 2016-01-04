#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>

using std::string;

int main()
{
    std::ifstream ifs("../book/book.txt");
    std::istream_iterator<string> in(ifs), eof;
    std::vector<string> str;
    std::copy(in, eof, back_inserter(str));
    
    std::copy(str.cbegin(), str.cend(), std::ostream_iterator<string>(std::cout, "\n"));
}
