#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currItem, valItem;
    if (std::cin >> currItem)
    {
        int ctn = 1;
        while(std::cin >> valItem)
        {
            if (currItem.isbn() == valItem.isbn())
                ctn++;
            else
            {
                std::cout << currItem << " occurs " << ctn << " times " 
                    << std::endl;
                currItem = valItem;
            }
        }
        std::cout << currItem << " occurs " << ctn << " times " << std::endl;
    }
    return 0;
}
