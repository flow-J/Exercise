#include <iostream>

template <typename Item>
class Stack
{
private:

public:
    Stack(int);
    int empty() const;
    void push(Item item);
    Item pop();
};
