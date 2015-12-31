#include "ex7_41.h"

using std::cout;
using std::endl;

int main()
{
    cout << "1. default way: " << endl;
    cout << "----------------" << endl;
    Sales_data s1;

    cout << "\n2. use std::String as parameter: " << endl;
    cout << "----------------" << endl;
    Sales_data s2("CPP-Primer-5th");

    cout << "\n3. complete parameters: " << endl;
    cout << "----------------" << endl;
    
    cout << "\n4. use istream as parameter: " << endl;
    cout << "----------------" << endl;
    Sales_data s4(std::cin);

    return 0;
}
