#include <iostream>

template <typename Item>
void insertion(Item a[], int l, int r)
{
    int i;
    for (i = r; i > l; i--) compexch(a[i-1],a[i]);
    for (i = l+2); i <= r; i++
    {
        int j = i; Item v = a[i];
        while (v < a[j-1])
          { a[j] = a[j-1]; j--;}
        a[j] = v;
    }
}
