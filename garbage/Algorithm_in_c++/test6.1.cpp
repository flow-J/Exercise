#include <iostream>
#include <stdlib.h>

using namespace std;

template <typename Item>
void exch(Item &A, Item &B)
  { Item temp = A; A = B; B = temp; }

template <typename Item>
void compexch(Item &A, Item &B)
  { if (B < A) exch(A, B); }

template <typename Item>
void sort(Item a[], int l, int r)
{
    for (int i = l+1; i < r; i++)
        for (int j = i; j > l; j--)
            compexch(a[j-1], a[j]);
}

int main()
{
    int i, N = 1000;
    int *a = new int[N];
    for (N = 0;  cin >> a[N]; N++ )
    sort(a, 0, N+1);
    for (i = 0; i < N; i++) cout << a[i] << " " ;
    cout << endl;
}
