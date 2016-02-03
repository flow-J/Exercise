#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;
using std::cout;
using std::cerr;
using std::endl;

int main()
{
    ifstream ifs("./book/book.txt");
    if (!ifs)
    {
        cerr << "No data?" << endl;
        return -1;
    }
    
    vector<string> vecLine;
    string line;
    while (getline(ifs, line))
        vecLine.push_back(line);

    for (auto &s : vecLine)
    {
        istringstream iss(s);
        string word;
        while (iss >> word)
            cout << word << endl;
    }

    return 0;
}
