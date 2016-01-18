#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

#include <random>
using std::default_random_engine;
using std::uniform_int_distribution;

#include <ctime>
using std::time;

#include <string>
using std::string;

#include <algorithm>
using std::sort;
using std::find_if;

#include <utility>
using std::pair;

int main()
{
    typedef pair<string, string> ps;
    ifstream i("d.txt");
    vector<ps> dict;
    string str1, str2;

    while (i >> str1 >> str2)
    {
        dict.emplace_back(str1, str2);
    }
    i.close();
    
    sort(dict.begin(), dict.end(), [](const ps &_ps1, const ps &_ps2){ return _ps1.first < _ps2.first; });
    i.open("i.txt");
    default_random_engine e(time(0));
    while (i >> str1)
    {
        vector<ps>::const_iterator it = find_if(dict.cbegin(), dict.cend(),
                [&str1](const ps &_ps){ return _ps.first == str1; });

        if (it == dict.cend())
        {
            cout << str1 << ' ';
        }
        else
        {
            uniform_int_distribution<unsigned> u(0, find_if(dict.cbegin(), dict.cend(),
                        [&str1](const ps &_ps){ return _ps.first > str1; }) - it - 1);
            cout << (it + u(e))->second << ' ';
        }
    }

    return 0;
}
