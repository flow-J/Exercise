#include <string>
#include <fstream>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;

int main()
{
    ifstream ifs("../book/letter.txt");
    if (!ifs) return -1;
    
    string longest;
    auto updata_with = [&longest](string const& curr)
    {
        if (string::npos == curr.find_first_not_of("aceimnorsuvwxz"))
            longest = longest.size() < curr.size() ? curr : longest;
    };
    for (string curr; ifs >> curr; updata_with(curr));
    cout << longest << endl;

    return 0;
}
