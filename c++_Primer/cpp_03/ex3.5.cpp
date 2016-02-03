#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
    string con;
    for(string str;cin >> str;con += str)
        cout << con << endl;
}
