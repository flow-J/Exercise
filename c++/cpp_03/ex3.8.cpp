#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
    string str("Hello");
    
    int i = 0;
    while (i < str.size())
        str[i++] = 'x';
    cout << str << endl;

    for (i = 0; i < str.size(); ++i)
        str[i] = 'x';
    cout << str << endl;
}
