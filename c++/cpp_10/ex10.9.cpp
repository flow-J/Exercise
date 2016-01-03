#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template<typename Sequence>
auto println(Sequence const& seq) -> std::ostream&
{
    for (auto const& elem : seq)
        std::cout << elem << " ";
    return std::cout << std::endl;
}

auto eliminate_duplicates(std::vector<std::string>& words) -> std::vector<std::string>&
{
    std::sort(words.begin(), words.end());
    println(words);

    auto new_end = std::unique(words.begin(), words.end());
    println(words);

    words.erase(new_end, words.end());
    return words;
}

int main()
{
    std::vector<std::string> words{"a", "v", "a" , "s", "a", "a"};
    println(words);
    println(eliminate_duplicates(words));

    return 0;
}
