#include <iostream>
#include <forward_list>

using std::forward_list;
using std::cout;
using std::endl;

/*
auto remove_odds(forward_list<int>& flist)
{
    auto is_odd = [] (int i)
    {
        return i & 0x1;
    };
    flist.remove_if(is_odd);
}

int main()
{
    forward_list<int> data = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    remove_odds(data);
    for (auto i : data)
        cout << i << " ";

    return 0;
}*/



int main()
{
    forward_list<int> flst = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if (*curr % 2)
            curr = flst.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }
    }

    for (auto f : flst)
        cout << f << " ";
    cout << endl;
}
