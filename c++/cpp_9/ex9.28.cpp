#include <iostream>
#include <forward_list>
#include <string>

void find_and_insert(forward_list<string>& list,string const& to_find, string const& to_add)
{
    auto prev = list.before_begin();
    for (auto curr = list.begin(); curr != list.end(); prev = curr++)
    {
        if (*curr == to_find)
        {
            list.insert_after(curr, to_add);
            return ;
        }
    }
    list.insert_after(prev, to_add);
}


