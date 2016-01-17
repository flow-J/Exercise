#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    regex r("[[:alnum:]]*[^c]ei[[:alpha:]]*", regex::icase);
    string s;
    cout << "please input a word! Input 'q' to quit!" << endl;
    while (cin >> s && s != "q")
    {
        if (std::regex_match(s, r))
            cout << "Input word " << s << " is okay!" << endl;
        else
            cout << "Input word " << s << " is not okay!" << endl;

        cout << "Please input a word! Input 'q' to quie" << endl;
    }

    cout << endl;


}
