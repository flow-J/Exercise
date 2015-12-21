#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

int main()
{
    vector<int> num{1 ,2 ,3 , 4, 5, 6, 7, 8, 9, 10};

    for (auto i : num)
    {
        cout << ((i & 0x1) ? i * 2 : i) << " ";
    }
    cout << endl;

}
