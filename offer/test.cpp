#include <string>
#include <vector>
#include <iostream>

using namespace std;

int strToInt(char *string)
{
    int number = 0;
    while (*string != 0)
    {
        number = number * 10 + *string -'0';
        ++string;
    }
    return number;
}

int main()
{
    char str[] = "hello,nerd.";
    auto num = strToInt(str);
    cout << num << endl;
}

