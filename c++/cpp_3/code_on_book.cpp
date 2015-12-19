
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
/*
int main()
{
    string s;
    cin >> s;
    cout << s << endl;
    return 0;
}*/
/*

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
int main()
{
    string word;
    while (cin >> word)
        cout << word << endl;
    return 0;
}*/



/*
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
    string line;

    while (getline(cin, line))
        cout << line << endl;
    return 0;
}*/

/*
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::cin;
using std::endl;

int main()
{
string line;
while (getline(cin, line))
    if (line.size() > 80)
        cout << line << endl;
}
*/

int main()
{
    string str("some string");

    for (auto c : str)
        cout << c << endl;
}
