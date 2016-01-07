#include <iostream>
#include <memory>

void process(std::shared_ptr<int> ptr)
{
    std::cout << "inside the process function:" << ptr.use_count() << "\n";
}

int main()
{
    std::shared_ptr<int> p(new int(42));
    process(std::shared_ptr<int>(p));

    std::cout << p.use_count() << "\n";
    auto q = p;
    std::cout << p.use_count() << "\n";
    std::cout << "the int p now points to is:" << *p << "\n";
    return 0;
}
