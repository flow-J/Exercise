#include <iostream>
#include <string>
#include <vector>
#include <list>

using std::cout;
using std::string;
using std::list;
using std::endl;
using std::vector;

int main()
{
    list<int> svec(5, 4);
    vector<int> ivec(5,5);

    vector<double> dvc(svec.begin(), svec.end());
    for (auto i : svec) cout << i << " ";
    cout << endl;
    for (auto d : dvc) cout << d << " ";
    cout << endl;

    vector<double> dvc2(ivec.begin(), ivec.end());
    for (auto i : ivec) cout << i << " ";
    cout << endl;
    for (auto d : dvc2) cout << d << " ";
    cout << endl;

    return 0;
}
