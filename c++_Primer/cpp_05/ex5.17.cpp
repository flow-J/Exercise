#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

int main()
{
    vector<int> foo1 = {0, 1, 1, 2};
    vector<int> foo2 = {0, 1, 1, 2, 3, 5, 8};

    int size = (foo1.size() < foo2.size()) ? foo1.size() : foo2.size();
    
    for (int i = 0; i != size; ++i)
    {
        if (foo1[i] != foo2[i])
            return false;
        return true;
    }
}
