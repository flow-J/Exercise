#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
    string curr, prev;

    while (cin >> curr)
    {
        if (isupper(curr[0]) && curr == prev)
            cout << curr << " occurs twice in succession." << endl;
            prev = curr;
            continue;

    }
}
