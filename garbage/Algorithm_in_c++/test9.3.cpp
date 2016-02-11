template <typename Item>
void fixUp(Item a[], int k)
{
    while (k > 1 && a[k/2] < a[k])
    { exch(a[k], a[k/2]); k = k/2; }
}
