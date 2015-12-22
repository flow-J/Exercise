#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (cin >> ch)
        switch (ch)
        {
            case 'a':
            case 'A':
                ++aCnt;
                break;
            case 'e':
            case 'E':
                ++eCnt;
                break;
            case 'i':
            case 'I':
                ++iCnt;
                break;
            case 'o':
            case 'O':
                ++oCnt;
                break;
            case 'u':
            case 'U':
                ++uCnt;
                break;
        }

    cout << "Number of vowel a(A): \t" << aCnt << '\n'
        << "Number of vowel a(E): \t" << eCnt << '\n'
        << "Number of vowel a(I): \t" << iCnt << '\n'
        << "Number of vowel a(O): \t" << oCnt << '\n'
        << "Number of vowel a(U): \t" << uCnt << endl;
    
    return 0;
}
