#include <iostream>
#include <list>

using std::list;
using std::cout;
using std::advance;

auto remove_evens_and_double_odds(list<int>& data)
{
    for(auto cur = data.begin(); cur != data.end();)
        if (*cur & 0x1)
            cur = data.insert(cur, *cur), advance(cur, 2);
        else
            cur = data.erase(cur);
}

int main()
{
    list<int> data { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    remove_evens_and_double_odds(data);
    for (auto i : data) cout << i << " ";

    return 0;
}
