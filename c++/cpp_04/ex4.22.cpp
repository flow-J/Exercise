#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    for (unsigned g = 0; cin >> g;)
    {
        auto finalgrade = (g > 90) ? "High pass" : (g < 60 ) ? " fail " : (g < 75 ) ? "low pass" : "pass";
        cout << finalgrade << endl;

        if (g > 90)         cout << "high pass";
        else if (g < 60)    cout << "fail";
        else if (g < 75)    cout << "low pass";
        else                cout << "pass";

        cout << endl;
    }
}
