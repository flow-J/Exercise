#include <iostream>
#include <string>

struct Sales_data
{
    std::string bookNO; // 书的编号
    unsigned units_sold = 0; // 销售量
    double revenue = 0.0; // 收入
};

int main()
{
    Sales_data book1, book2;
    double price1, price2;
    
    std::cin >> book1.bookNO >> book1.units_sold >> price1;
    std::cin >> book2.bookNO >> book2.units_sold >> price2;
    book1.revenue = book1.units_sold * price1;
    book2.revenue = book2.units_sold * price2;

    if(book1.bookNO == book2.bookNO)
    {
        unsigned totalCnt = book1.units_sold + book2.units_sold;
        double totalRevenue = book1.revenue + book2.revenue;
        std::cout << book1.bookNO << " " << totalCnt << " "
            << totalRevenue;
        if (totalCnt != 0)
        {
            std::cout << totalRevenue / totalCnt << std::endl;
            return 0;
        }
        else
        {
            std::cout << "(no sales)" << std::endl;
            return -1;
        }
    }
    else
    {
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;
    }
}
