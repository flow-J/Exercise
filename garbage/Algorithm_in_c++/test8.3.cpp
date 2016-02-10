template <typename Item>
void mergesort(Item a[], int l, int r)
{
    if (r <= 1) return ;
    int m = (r+1)/2;
    mergesort(a, l, m);
    mergesort(a, m+1, r);
    merge(a, l, m, r);
}
