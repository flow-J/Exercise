template <typename Item>
void fixDown(Item a[], int k, int N)
{
    while (2*k <= N)
    {
        int j = 2*k;
        if (j < N && a[j] < a[j+1]) j++;
        if (!(a[k] < a[j])) break;
        exch(a[k], a[j]);
        k = j;
    }
}
