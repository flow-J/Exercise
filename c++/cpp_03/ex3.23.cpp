#include <iostream>
#include <iterator>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::endl;

int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8,9};
    
    for (auto it = vec.begin(); it != vec.end(); ++it)
        cout << *it * 2 << " ";
    cout << endl;
}
