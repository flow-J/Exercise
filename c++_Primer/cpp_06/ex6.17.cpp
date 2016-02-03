#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

bool any_capital(string const& str)
{
    for (auto s : str)
        if (isupper(s)) return true;
    return false;
}

void to_lowercase(string& str)
{
    for (auto& s : str) s = tolower(s);       
}

int main()
{
    string s;
    while (cin >> s)
        if (any_capital(s))
            to_lowercase(s);
    cout << s << endl;
}
