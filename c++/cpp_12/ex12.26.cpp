#include <iostream>
#include <string>
#include <memory>

void input_reverse_output_string(int n)
{
    std::allocator<std::string> alloc;
    auto const p = alloc.allocate(n);
    std::string s;
    auto q = p;
    while (std::cin >> s && q != p +n)
        alloc.construct(q++, s);
    
    while (q != p)
    {
        std::cout << *--q << " ";
        alloc.destroy(q);
    }
    alloc.deallocate(p, n);
}

int main()
{
    input_reverse_output_string(5);
}
