#include "FIFO_array.hpp"
#include <iostream>

int main()
{
    QUEUE<int> *q;
    q->put(1); q->put(2);
    auto i = q->get();
    std::cout << i << std::endl;
}
