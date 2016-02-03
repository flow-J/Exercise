#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

int main()
{
    std::vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::list<int> lst1, lst2, lst3;
    std::copy(vec.begin(), vec.end(), std::front_inserter(lst1));
    std::copy(vec.cbegin(), vec.cend(),std::inserter(lst2, lst2.begin()));
    std::copy(vec.cbegin(), vec.cend(), std::back_inserter(lst3));
    
}
