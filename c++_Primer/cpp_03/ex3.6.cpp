#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
    string str("Hello World");
    for (auto &c : str)
        c = 'x';
    cout << str << endl;
}
