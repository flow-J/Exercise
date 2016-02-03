#include <vector>
#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>

int main()
{
    std::vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    /*
    for (auto r_iter = vec.crbegin(); r_iter != vec.rend();++r_iter)
        std::cout << *r_iter << std::endl;***********************
        ********************************************************/
/*
    for (auto iter = vec.end(); iter != vec.begin();--iter)
        std::cout << *iter << std::endl; // bug
*/  
    for (auto it = std::prev(vec.cend()); true; --it)
    {
        std::cout << *it << " ";
        if (it == vec.cbegin()) break;
    }
    std::cout << std::endl;
    
    std::list<int> lst = { 1, 2, 3, 4, 0, 5, 6 };
    auto found_0 = std::find(lst.crbegin(), lst.crend(), 0);
/*    int num = std::find(list.begin(), list.end(), 0);*/

    std::list<int> ret_lst;
    std::copy(vec.crbegin()+3, vec.crbegin() + 8, std::back_inserter(ret_lst));

    for (auto i : ret_lst) std::cout << i << " ";
    std::cout << std::endl;

}
