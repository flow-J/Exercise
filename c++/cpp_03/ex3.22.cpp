#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::isalpha;
using std::endl;

int main()
{
    vector<string> text;
    
    for(string line;getline(cin, line); text.push_back(line));

    for (auto &word : text)
    {
        for (auto &ch : word)
            if (isalpha(ch)) ch = toupper(ch);
        cout << word << endl;
    }   
    return 0;
}
