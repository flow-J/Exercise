#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

int main()
{
    vector<string> vec;
    for (string word; cin >> word; vec.push_back(word));
    for (auto &str : vec)
    {
        for (auto &c : str )
            c = toupper(c);
    }
    for(int i = 0; i != vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
