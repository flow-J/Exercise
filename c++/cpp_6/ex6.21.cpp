#include <iostream>
using std::cout;

int larger_one(const int i,const int *p)
{
    return (i > *p) ? i : *p;
}

int main()
{
    int foo = 10;
    cout << larger_one(7, &foo) << std::endl;
}
