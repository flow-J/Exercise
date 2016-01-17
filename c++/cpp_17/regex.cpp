#include <regex>
#include <iostream>
#include <string>

using std::string;
using namespace std;
int main()
{
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    smatch results;
    string test_str = "receipt freind theif receive";

    if (regex_search(test_str, results, r))
        std::cout << results.str() << std::endl;
}
