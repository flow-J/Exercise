#include <iostream>
#include <string>

int main()
{
    std::string read, tmp;
    while (std::cin >> read)
    {
        if (read == tmp)
            break;
        else
            tmp = read;
    }

    if (std::cin.eof())
        std::cout << "no words are repeated. " << std::endl;
    else
        std::cout << read << " occurs twice in succession." << std::endl;
    return 0;
}
