#include <iostream>
int main()
{
    int foo = 10;
    while(foo >= 0)
        std::cout << foo-- << " " << std::endl; //foo--先调用后运算，如果是--foo的话，output就是9....-1啦。
    return 0;
}
