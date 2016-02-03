#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total;
    if(std::cin >> total){
        Sales_item foo;
        while(std::cin >> foo)
        {
            if(total.isbn() == foo.isbn())
                total += foo;
            else
            {
                std::cout << total << std::endl;
                total = foo;
            }
            std::cout << total << std::endl;
        }
    }
    else
    {
        std::cout << "No data?" << std::endl;
        return -1;
    }
    return 0;
}
