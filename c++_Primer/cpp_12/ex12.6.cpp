#include <iostream>
#include <vector>

using Ptr = std::vector<int>*;

auto make_dynamically()
{
    return new std::vector <int> { };
}

auto populate(Ptr vec)
{
    for (int i; std::cout << "Pls Enter:\n", std::cin >> i; vec->push_back(i));
    return vec;
}

auto print(Ptr vec) -> std::ostream&
{
    for (auto i : *vec) std::cout << i << " ";
    return std::cout;
}

int main()
{
    auto vec = populate(make_dynamically());
    print(vec) << std::endl;
    delete vec;

    return 0;
}
