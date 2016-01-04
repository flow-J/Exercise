#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        if (str1 == str2)
            cout << "equal!" << endl;
        else
            cout << "The big one is " << ((str1 > str2) ? str1 : str2) << endl;
        return 0;
    }
}
