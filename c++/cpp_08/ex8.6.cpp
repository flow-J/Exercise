#include <fstream>
#include <iostream>

#include "../cpp_7/ex7_26.h"

using std::ifstream;
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);

    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(input, trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    return 0;
}
