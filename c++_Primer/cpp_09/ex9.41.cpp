#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;

int main()
{
    vector<char> v{ 'f', 'l', 'o', 'w'};
    string str(v.cbegin(), v.cend());
    cout << str << endl;
}
