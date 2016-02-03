#include <iostream>

int main()
{
    int i = 42;
    auto add = [i](int num){return i + num; };
}
