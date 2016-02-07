#include <iostream>
#include <string.h>
using namespace std;
/*
auto check(int str[])
{
    
    auto *p = str; int *foo = NULL;
    while (*foo++ = *p++);
    for (auto t[] = {0}, i = 0; ;;)
    {
        if (foo[i] == str[i++])
    }
}
*/
/*
bool isAym(string *begin, string *end)
{
    if (begin == NULL || end == NULL || begin > end)
    {
        return false;
    }
    while (begin<end)
    {
        if (*begin != *end)
        {
            return false;
        }
        begin++;
        end--;
    }
    return true;
}*/

int main()
{
    char *str = "ifihadahifi";
    int n = strlen(str);
    bool flag = true;
    int i;
    for (i = 0; i < n/2;++i)
    {
        if (str[i]!=str[n-1-i])
        {
            flag = false;
            break;
        }
    }
    cout << (flag ? "isAym" : "not aym") << endl;
    return 0;
}
