#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
    smatch results;
    string filename;
    while (cin >> filename)
        if (regex_search(filename, results, r))
            cout << results.str() << endl;
}
