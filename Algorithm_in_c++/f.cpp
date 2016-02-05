#include <iostream>

using namespace std;
int main()
{
 //   int f[100] = {0,1,2};
    int f[100];
    f[0] = 0; f[1] = 1;
    for (int i = 2; i < 10; i++)
    {
        f[i] = f[i-1] + f[i-2];
        for (auto i : f)
            cout << i << " ";
        cout << endl;
    }
}
