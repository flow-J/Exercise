#include <iostream>
#include <string>

using namespace std;

template <typename Item>
void exch(Item &A, Item &B)
{ Item temp = A; A = B; B = temp; }

template <typename Item>
void selection(Item a[], int l, int r)
{
    for (int i = l; i < r; i++)
    {
        int min = i;
        for (int j = i+1; j <= r; j++)
            if (a[j] < a[min]) min = j;
        exch(a[i], a[min]);
    }
    for (int i = 0; i < r;i++)
        cout << a[i] << " ";
    cout << endl;
}

