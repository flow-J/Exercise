#include "ex14.49.h"

int main()
{
    Data date(12, 4, 2015);
    if (static_cast<bool>(date))
        std::cout << date << std::endl;
}
