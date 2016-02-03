#include <iostream>
#include <stdexcept>

using std::cout;
using std::runtime_error;
using std::cin;
using std::endl;

int main(void)
{
    for (int i, j; cout << "Input two integer:\n", cin >> i >> j; )
    {
        try
        {
            if (j == 0)
                throw runtime_error("divisor is 0");
            cout << i / j << endl;
        }
        catch (runtime_error err)
        {
            cout << err.what() << "\n";
        }
    }

    return 0;
}
