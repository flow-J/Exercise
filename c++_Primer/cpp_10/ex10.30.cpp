#include <iostream>

int main()
{
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec;
    while (in_iter != eof)
        vec.push_back(*in_iter++);
    std::sort(vec.begin(), vec.end());
    std::copy(vec.begin(), vec.end(),ostream_iterator<int>(std::cout, " "));
}
