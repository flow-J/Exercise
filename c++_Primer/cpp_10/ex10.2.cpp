#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    std::list<string> str = {"abcdefg"};
    auto val = "a";
    cout << std::count(str.cbegin(), str.cend(), val) << endl;
}
