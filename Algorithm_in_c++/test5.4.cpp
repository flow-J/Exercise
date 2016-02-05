#include <iostream>

char *a; int i;
int eval()
{
    int x = 0;
    while (a[i] == ' ') i++;
    if (a[i] == '+')
    { i++; return eval() + eval(); }
}
