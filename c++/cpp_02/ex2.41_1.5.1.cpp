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
    Sales_data book;
    double price;
    std::cin >> book.bookNO >> book.units_sold >> price;
    book.revenue = book.units_sold * price;
    std::cout << book.bookNO << " " << " " << book.units_sold <<
        " " << book.revenue << " " << price << std::endl;
    return 0;
}
