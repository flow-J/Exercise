#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::cin;
using std::endl;

int main()
{
    string rsp;
    do {
        cout << "please enter two string: ";
        string str1, str2;
        cin >> str1 >> str2;
        cout << "The shorter one is " << (str1 <= str2 ? str1 : str2)
            << "\n\n"
            << "More? Enter yes or no: ";
        cin >> rsp;
    } while (!rsp.empty() && rsp[0] != 'n');
}
