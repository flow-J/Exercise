#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
    string str;
    for(string buff;cin >> buff;str += (str.empty() ? "" : " ") + buff)
        cout << str << endl;
}
