#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

auto replace_with(string &s, string const& oldVal, string const& newVal)
{
    for (size_t pos = 0; pos <= s.size() - oldVal.size();)
        if (s[pos] == oldVal[0] && s.substr(pos, oldVal.size()) == oldVal)
            s.replace(pos, oldVal.size(), newVal),
            pos += newVal.size();
        else
            ++pos;
}

int main()
{
    string str{"To drive straight thru is a foolish, tho courageous act."};
    replace_with(str, "tho", "though");
    replace_with(str, "thru", "through");
    cout << str << endl;
    return 0;
}
