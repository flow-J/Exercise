#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern, regex::icase);

    string file;
    for (sregex_iterator it(file.begin(), file.end(), r), end_it;
            it !=end_it; ++it)
        cout << it->str() << endl;
}
