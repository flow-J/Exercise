#include <iostream>
#include <string>

struct Sales_data
{
    std::string bookNO;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data total;
    double totalPrice;
    if(std::cin >> total.bookNO >> total.units_sold >> totalPrice)
    {
        Sales_data trans;
        double transPrice;
        while(std::cin >> trans.bookNO >> trans.units_sold >> transPrice)
        {
            trans.revenue = trans.units_sold * transPrice;
            if(total.bookNO == trans.bookNO)
            {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else
            {
                std::cout << total.bookNO << " " << total.units_sold << " " << total.revenue << " ";
                if(trans.units_sold != 0)
                    std::cout << total.revenue / total.units_sold<< " " << std::endl;
                else
                    std::cout << "(no sales)" << std::endl;
                total.bookNO = trans.bookNO;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
        if(total.units_sold != 0)
            std::cout << total.revenue / total.units_sold<< " " << std::endl;
        else
            std::cout << "(no sales)" << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "no data!" << std::endl;
        return -1;
    }
}
