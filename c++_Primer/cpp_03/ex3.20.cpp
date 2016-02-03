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
    
    for(int i = 0;i != ivec.size() - 1;++i)
        cout << ivec[i] + ivec[i+1] << " ";
    cout << endl;
}
