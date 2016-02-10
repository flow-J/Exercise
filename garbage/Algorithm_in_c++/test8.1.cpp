template <typename Item>
void mergeAB(Item c[], Item a[], int N,
                       Item b[], int M)
{
    for (int i = 0, j = 0, k = 0; k < N+M; k++)
    {
        if (i == N) { c[k] = b[j++]; continue; }
        if (j == M) { c[k] = a[i++]; continue; }
        c[k] = (a[i] < b[j] ? a[i++] : b[j++]; )
    }
}
