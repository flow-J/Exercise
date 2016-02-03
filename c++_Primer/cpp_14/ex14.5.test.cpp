#include "ex14.5.h"

int main()
{
    Book book1(123, "CP5", "Lippman", "42");
    Book book2(123, "CP5", "Lippman", "42");

    if(book1 == book2)
        std::cout << book1 << std::endl;
}
