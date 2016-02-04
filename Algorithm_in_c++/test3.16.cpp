#include <iostream>

int **a = malloc2d(M, N);
int **malloc2d(int r, int c)
{
    int **t = new int*[r];
    for (int i = 0; i < r; i++)
        t[i] = new int [c];
    return t;
}
