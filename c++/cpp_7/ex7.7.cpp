#include <iostream>
#include "ex7_6.h"

using std::endl;

int main()
{
    Sales_data total;
    if (read(std::cin,total))
    {
        Sales_data trans;
        while (read(std::cin,trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(std::cout,total) << endl;
                total = trans;
            }
        }
        print(std::cout,total) << endl;
    }
    else
    {
        std::cerr  << "No data? " << endl;
    }
}
