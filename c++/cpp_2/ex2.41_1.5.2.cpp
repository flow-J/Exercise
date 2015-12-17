#include <iostream>
#include <string>

struct Sales_data
{
    std::string bookNO;
    std::string bookName;
    unsigned units_sold = 0;
    double price = 0.0;
    double revenue = 0.0;
};

int main()
{
    Sales_data data1, data2;
    double price = 0; // 图书价格
    // 读入data1 和 data2 的代码
    // 如果相同， 求data1 和 data2 的总和
    std::cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;


    // 检查data1 和 data2 是否相同的代码
    if (data1.bookNo == data2.bookNo)
    {
        unsigned totalCNt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;

        std::cout << data1.bookNo << " " << totalCnt
            << " " << totalRevenue << " ";

        if (totalCNt != 0)
            std::cout << totalRevenue/totalCNt << std::endl;
        else
            std::cout << "(no sales)" << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "Data must refer to the same ISBN"
            << std::endl;
        return -1;
    }

}
