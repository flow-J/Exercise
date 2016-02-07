#include <>


template <typename Item>
void shellsort(Item a[], int l, int r)
{
    int h;
    for (h = 1; h <= (r-l)/9; h = 3*h+1) ;
    for ( ; h > 0; h /= 3)
        for (int i = l+h; i <= r; i++)
        {
            int j = i; Item v = a[i];
            while (j >= l+h && v < a[j-h])
            { a[j] = a[j-h]; j-= h; }
            a[j] = v;
        }
}
