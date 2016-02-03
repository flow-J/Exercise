#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::vector;
using std::endl;
using std::list;
using std::end;

int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
/*
    vector<int> vec;
    for (auto i : ia) vec.push_back(i);
    list<int> lis;
    for (auto i : ia) lis.push_back(i);
*/

    vector<int> vec(ia, end(ia));
    list<int> lis(vec.begin(), vec.end());

    for (auto it = lis.begin(); it != lis.end(); )
        if (! (*it &0x1)) 
            it = lis.erase(it);
        else ++it;

    for (auto it = vec.begin(); it != vec.end(); )
        if(! (*it &0x1)) 
            it = vec.erase(it);
        else ++it;

    cout << "list : ";
    for (auto i : lis) cout << i << " ";
    cout << "\nvector : ";
    for(auto i : vec)  cout << i << " ";
    cout << std::endl;
}
