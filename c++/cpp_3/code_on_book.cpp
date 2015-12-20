#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iterator>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

/*
int main()
{
    string s;
    cin >> s;
    cout << s << endl;
    return 0;
}*/
/*

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
int main()
{
    string word;
    while (cin >> word)
        cout << word << endl;
    return 0;
}*/



/*
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
    string line;

    while (getline(cin, line))
        cout << line << endl;
    return 0;
}*/

/*
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::cin;
using std::endl;

int main()
{
string line;
while (getline(cin, line))
    if (line.size() > 80)
        cout << line << endl;
}
*/
/*
int main()
{
    string str("some string");

    for (auto c : str)
        cout << c << endl;
}*/
/*
int main()
{
    string s("Hello World!!!");

    decltype (s.size()) punct_cnt = 0;

    for (auto c : s)
        if (ispunct(c))
            ++punct_cnt;
    cout << punct_cnt
        << " punctuation characters in " << s << endl;
}*/
/*

int main()
{
    const string hexdigits = "0123456789ABCDEF";
    cout << "Enter a series of numbers between 0 and 15"
        << " separated by spaces. HIt ENTER when finished:  "
        << endl;
    string result;
    string::size_type n;
    while (cin >> n)
        if (n < hexdigits.size())
            result += hexdigits[n];
    cout << "Your hex number is: " << result << endl;
}
*/




/*
int main()
{
    std::vector<int> fuck;
    for (int i; cin >> i;fuck.push_back(i));
    return 0;
}*/
/*
int main()
{
    vector<int> v{1,2,3,4,5,6,7,8,9};
    for (auto i : v)
        i *= i;
    for (auto i : v)
        cout << i << " " << endl;
}
*/
/*
int main()
{
    vector<int> ivec{42};
}
*/

/*
int main()
{
    vector<int> text(10, 2);
    for (auto it = text.cbegin();
            it != text.cend() && !it->empty(); ++it)
    cout << *it << endl;
}*/



int main()
{
    auto mid = vi.begin() + vi.size() / 2;
}
