/*
 * #include <iostream>
int main()
{
    int sum = 0, val = 1;
    while(val <= 10){
        sum += val;
        ++val;
    }
    std::cout << "Sum of 1 to 10 inclusive is "
        << sum << std::endl;
    return 0;
}*/
/*
#include <iostream>
int main()
{
    int sum = 0;
    for(int val = 1; val <= 10; ++val)
        sum += val;
    std::cout << "Sum of 1 to 10 inclusive is "
        << sum << std::endl;
    return 0;
}*/
/*
#include <iostream>
int main()
{
    int sum = 0, value = 0;
    while(std::cin >> value)
        sum += value;
    std::cout << "Sum is: " << sum << std::endl;
    return 0;
}*/
/*
#include <iostream>
int main()
{
    int currVal = 0, val = 0;

    if (std::cin >> currVal)
    {
        int cnt = 1;
        while (std::cin >> val) {
            if (val == currVal)
                ++cnt;
            else {
                std::cout << currVal << " occurs "
                    << cnt << " times" << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs "
            << cnt << " times" << std::endl;
    }
    return 0;
}*/

/*
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item book;
    
    std::cin >> book;
    std::cout << book << std::endl;
    return 0;
}*/
/*
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    std::cout << item1 + item2 << std::endl;
    return 0;
}*/
/*
#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;

    if (item1.isbn() == item2.isbn()) {
        std::cout << item1 + item2 << std::endl;
        return 0;
    } else {
        std::cerr << "Data mush refer to same ISB"
            << std::endl;
        return -1;
    }
}*/


#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item total;
    if (std::cin >> total)
    {
        Sales_item trans;
        while (std::cin >> trans)
        {
            if (total.isbn() == trans.isbn())
                total += trans;
            else
            {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    }
    else
    {
        std::cerr << "No data!" << std::endl;
        return -1;
    }
    return 0;
}
