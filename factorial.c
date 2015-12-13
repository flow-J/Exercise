#include <stdio.h>


int factorial(int N)

{

    if (N == 0) return 1;

    else N*factorial(N-1);
    printf("%d",N);
}

char *a; int i;
int eval()
{
    int x = 0;
    while (a[i] == ' ') 
        i++;

    if(a[i] =='+')
    { i++; return eval() + eval(); }
    else if(a[i] == '*')
    {  i++; return eval() * eval();  }
   while((a[i] >= '0') && (a[i] <= '9')) 
       x = 10*x + (a[i++]-'0');
   return x;
}
