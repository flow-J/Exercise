template <typename Item>
void shuffle(Item a[], int l, int r)
{
    int i, j, m = (l+r)/2;
    static Item aux[maxN];
    for (i = l, j = 0; i <= r; i+=2, j++)
    { aux[i] = a[l+j]; aux[i+1] = a[m+1+j]; }
    for (i = l; i <= r; i++) { a[i] = aux[i]; }
}

template <typename Item>
void unshuffle(Item a[], int l, int r)
{
    int i, j, m = (l+r)/2;
    static Item aux[maxN];
    for (i = l, j = 0; i <= r; i+=2, j++)
    { aux[l+j] = a[i]; aux[m+1+j] = a[i+1]; }
    for (i = l; i <= r; i++)
    { a[i] = aux[i]; }
}
