#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::list;
using std::fill_n;

template<typename Sequence>
void print(Sequence const& seq)
{
    for (const auto& i : seq)
        cout << i << " ";
    cout << endl;
}


int main()
{
    vector<int> vec;
    list<int> lst;
    int i ;
    while (cin >> i)
        lst.push_back(i);
    vec.resize(lst.size());
    copy(lst.cbegin(), lst.cend(), vec.begin());

    vector<int> v;
    v.resize(10);
    fill_n(v.begin(), 10, 0);

    print(v);
    print(vec);
}
