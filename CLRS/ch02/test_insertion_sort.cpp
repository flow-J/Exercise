#include "insertion_sort.cpp"
#include <vector>
#include <deque>


int main()
{
    std::vector<int> sample = {5,1,2,3,4,5};
    insertion_sort(sample);
    for (auto i : sample)
        std::cout << i << " ";
    std::cout << std::endl;
}
