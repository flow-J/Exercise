#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;
using std::map;
using std::cin;
using std::cout;
using Families = map<string, vector<string>>;

auto make_families()
{
    Families families;
    for (string ln; cout << "Last name:\n", cin >> ln && ln != "@q";)
        for (string cn; cout << "|-Children's names:\n", cin >> cn && cn != "@q";)
            families[ln].push_back(cn);
    return families;
}

auto print(Families const& families)
{
    for (auto const& family : families)
    {
        cout << family.first << ":\n";
        for (auto const& child : family.second)
            cout << child << " ";
        cout << "\n";
    }
}

int main()
{
    print(make_families());
    return 0;
}
