#include <iostream>
#include <regex>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::regex;
using std::sregex_iterator;

int main()
{
    string s;
    cout << "input a sequence of words: ";
    getline(cin, s);
    cout << endl;
    cout << "Word(s) that violiate the \"ei\" grammar rule:" << endl;
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern, regex::icase);
    for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
        cout << it->str() << endl;

    return 0;
}
