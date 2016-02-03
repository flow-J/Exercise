#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int who_shorter(string const& bigger,const& shorter)
{
    if (shorter > bigger)
        return who_shorter(bigger, shorter);
    return shorter;
}

int main()
{
    string v1, v2;
    string rsp;
    do {
        cout << "enter two strings ";
        cin >> v1, v2;
        cout << "the shorter sting is " << who_shorter(v1, v2) << endl;
        cout << "More? Enter yes or no: ";
    }
}while(!rsp.empty() && rsp[0] != 'n');
