#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int compare(const void *i, const void *j)
  { return strcmp(*(char **)i, *(char **)j); }
int main()
{
    const int Nmax = 1000;
    const int Mmax = 10000;
    char *a[Nmax]; int N;
    char buf[Mmax]; int M = 0;
    for (N = 0; N < Nmax; N++)
    {
        a[N] = &buf[M];
        if (!(cin >> a[N])) break;
        M += strlen(a[N])+1;
    }
    qsort(a, N, sizeof(char*), compare);
    for (int i = 0; i < N; i++)
        cout << a[i] << endl;
}
