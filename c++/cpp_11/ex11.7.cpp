#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::map;
using Families = map<string, vector<string>>;


auto make_families()
{
    Families families;
    for (string ln;cout << "last name: \n", cin >> ln && ln != "@q";)
        for (string fn; cout << "|-first name: \n", cin >> ln && "@q";)
            families[ln].push_back(fn);
    return families;
}

auto print(Families const& families)
{
    for (auto const& family : families)
    {
        cout << family.first << "\n";
        for (auto const& last : family.second)
            cout << last << " ";
        cout << "\n";
    }
}

int main()
{
    print(make_families());
    return 0;
}
