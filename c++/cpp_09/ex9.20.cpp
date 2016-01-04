#include <list>
#include <deque>
#include <iostream>

using std::cout;
using std::list;
using std::deque;
using std::endl;

int main()
{
    list<int> num{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    deque<int> odd, even;
    for (auto i : num)
        (i & 0x1 ? odd : even).push_back(i);

    for (auto i : odd)
        cout << i << " " ;
    cout << endl;
    for (auto i : even)
        cout << i << " " ;
    cout << endl;
}
