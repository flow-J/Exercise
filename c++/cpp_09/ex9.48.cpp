#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string numbers("0123456789"), name("r2d2");
    cout << numbers.find(name) << endl;
}

