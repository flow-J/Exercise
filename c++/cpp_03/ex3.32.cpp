#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    vector<int> vec(10);
    
    for (auto i = 0; i < 10; ++i)
        vec[i] = i;

    for (auto foo : vec)
        cout << foo << " " ;
    cout << endl;
}
