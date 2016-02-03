#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::endl;

int main()
{
    vector<int> ivec;
    for(int i;cin >> i;ivec.push_back(i));
    
    auto size = ivec.size();
    if (size % 2 != 0) size = size / 2 +1;
    else size /= 2;


    for(int i = 0;i != size;++i)
        cout << ivec[i] + ivec[ivec.size() - i - 1] << " ";
    cout << endl;
}
