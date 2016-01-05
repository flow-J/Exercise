#include <map>
#include <iostream>
#include <string>

int main()
{
    std::map<std::string, std::list<size_t>>;

    std::map<std::vector<int>::iterator, int> mv;
    std::map<std::list<int>::iterator, int>ml;

    std::vector<int> vi;
    mv.insert(std::pair<std::vector<int>::iterator, int>(vi.begin(), 0));
    
    std::list<int> li;
    ml.insert(std::pair<std::list<int>::iteraor, int>(li.begin(), 0));

    return 0;
}
