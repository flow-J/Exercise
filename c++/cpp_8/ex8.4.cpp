#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::vector;
using std::string;
using std::ifstream;
using std::endl;

void ReadFileToVec(const string& fileName, vector<string>& vec)
{
    ifstream in(fileName);
    if (in)
    {
        string buf;
        while (std::getline(in, buf))
            vec.push_back(buf);
    }
}

int main()
{
    vector<string> vec;
    ReadFileToVec("./book/book.txt", vec);
    for (const auto &str : vec)
        cout << str << endl;
    return 0;
}
