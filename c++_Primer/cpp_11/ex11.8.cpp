#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::string> exclude = {"aa", "bb", "cc"};
    for (std::string word; std::cin >> word;) {
        if (std::find(exclude.begin(), exclude.end(), word) != exclude.end())
            std::cout << "excluded!" << std::endl;
        else
            exclude.push_back(word);
    }
    for (auto const& s : exclude) std::cout << s << " ";
    std::cout << std::endl;
}
