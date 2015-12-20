#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> str;
    std::string word;
    /*
    while (std::cin >> word)
    {
        str.push_back(word);
    }
    */
    
    for(std::string buffer; std::cin >> buffer; str.push_back(buffer));
    return 0;
}
