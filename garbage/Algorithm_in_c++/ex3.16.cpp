#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, size_t> num_count;
    size_t num = 0;
    while (cin >> num || num == 'c')
    {
        if (num < 1000)
            ++num_count[num];
    }
    for (auto &w : num_count)
        cout << w.first << " " << w.second << endl;
}
