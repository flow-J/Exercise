#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::istream_iterator<int> in_iter(std::cin), eof;
    std::vector<int> vec;
    while (in_iter != eof)
        vec.push_back(*in_iter++);
    std::sort(vec.begin(), vec.end());
    std::unique_copy(vec.cbegin(), vec.cend(),std::ostream_iterator<int>(std::cout, " "));
    std::cout << *in_iter << std::endl;
}
