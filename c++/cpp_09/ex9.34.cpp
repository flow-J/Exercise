#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;

int main()
{
    vector<int> data { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (auto cur = data.begin(); cur != data.end(); ++cur)
        if (*cur & 0x1)
            cur = data.insert(cur, *cur), ++cur;

    for (auto i : data)
        cout << i << " ";

    return 0;
}
