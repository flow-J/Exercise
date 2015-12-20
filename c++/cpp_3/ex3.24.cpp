#include <iostream>
#include <iterator>

using std::cout;
using std::cin;
using std::vector;
using std::endl;

int main()
{
    vector<int> v;
    for (int buffer;cin >> buffer;v.push_back(buffer));
    
    for (auto it = v.cbegin();it + 1 != v.cend();++it)
        cout << *it << *(it + 1) << " ";
    cout << endl;

    for (auto lft = v.cbegin(), rht = v. cend() - 1; lft <= rht; ++lft, --rht)
        cout << *lft + *rht << " ";
    cout << endl;

    return 0;
}
