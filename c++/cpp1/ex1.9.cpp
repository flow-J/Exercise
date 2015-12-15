#include <iostream>
int main()
{
    int sum = 0, foo = 50;
    while(foo <= 100){
        sum += foo;
        ++foo;
    }
    std::cout << "The sum is " << sum << std::endl;
}
