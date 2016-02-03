#include <list>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::list;
using std::endl;

int main()
{
    list<string> input;
    for (string str; cin >> str; input.push_back(str));
    for (auto iter = input.begin();iter != input.end(); ++iter)
        cout << *iter << endl;
}
