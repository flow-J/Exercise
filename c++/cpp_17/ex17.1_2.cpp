#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using namespace std;
int main()
{
    tuple<int, int, int> tup(10, 20, 30);
    tuple<string, vector<string>, pair<string, int>> tup2("string",{"c++"}, {"hello", 10} );
}
