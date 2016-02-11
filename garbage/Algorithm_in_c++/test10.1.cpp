const int bitsword = 32;
const int bitsbyte = 8;
const int bytesword = bitsword/bitsbyte;
const int R = 1 << bitsbyte;
    
    template <typename Item>
void quicksortB(Item a[], int l, int r, int d)
{
    int i = l, j = r;
    if (r <= l || d > bitsword) return ;
    while (j !=i )
    {
        while (digit(a[i], d) == 0 && (i < j)) i++;
        while (digit(a[j], d) == 1 && (j > i)) j--;
        exch(a[i], a[j]);
    }
    if (digit(a[r], d) == 0) j++;
    quicksortB(a, l, j-1, d+1);
    quicksortB(a, j, r, d+1);
}

template <typename Item>
void sort(Item a[], int l, int r)
{ quicksortB(a, l, r, 0); }

