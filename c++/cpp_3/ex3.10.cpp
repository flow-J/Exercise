#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
    string str("Hello,world.");

    for (auto c : str)
        if (!ispunct(c)) cout << c;
}
