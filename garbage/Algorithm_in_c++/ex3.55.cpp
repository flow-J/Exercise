#include <iostream>
#include <string>

using namespace std;
/*
auto count(string str[])
{
    int a[128] = {0}; int count = 0;
    for ( ;a[count];count++)
        a[str[count]]++;
    auto *p = a;
    return p;
}*/
int main()
{
    int a[128] = {0};
    char str[] = "abcdddddddd";
    for (int i = 0; str[i]; i++)
        a[str[i]]++;
    for (int j =0; j < 128; j++)
        if (a[j])
            cout << (char)j << " " << a[j] << endl;
}
