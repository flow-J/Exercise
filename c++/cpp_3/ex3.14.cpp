#include <iostream>
#include <vector>

int main()
{
    std::vector<int> foo;
    for (int i; std::cin >> i;foo.push_back(i));
    return 0;
}
