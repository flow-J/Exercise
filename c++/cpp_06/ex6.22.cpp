#include <iostream>

void swap(int*& lht,int*& rht)
{
    auto tmp = lht;
    lht = rht;
    rht = tmp;
}

int main()
{
    int i = 40, j = 50;
    auto lht = &i;
    auto rht = &j;
    swap(lht,rht);
    std::cout << *lht << " " << *rht << std::endl;
}
