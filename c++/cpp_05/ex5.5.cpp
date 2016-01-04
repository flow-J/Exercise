#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::endl;

int main()
{
    vector<string> scores = { "f", "D", "C", "B", "A", "A++"};
    
    for (int g; cin >> g;)
    {
        string letter;
        if (g < 60)
        {
            letter = scores[0];
        }
        else
        {
            letter = scores[(g - 50) / 10];
            if (g != 100)
                letter += g % 10 > 7 ? "+" : g % 10 < 3 ? "-" : "";
            cout << letter << endl;
        }
    }

    return 0;
}
