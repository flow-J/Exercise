#include <iostream>
#include <string>
#include "ex7_2.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;


int main()
{
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
                total = trans;
            }
        }

        cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;

    }
    else
    {
        std::cerr << "NO data? " << endl;
        return -1;
    }

    return 0;
}
