template <typename Item>
class PQ
{
private:
    Item *pq;
    int N;
public:
    PQ(int maxN)
    { pq = new Item[maxN]; N = 0; }
    int empty() const
    { return N == 0; }
    void insert(Item item)
    { pq[N++] = item; }
    Item getmax()
    {
        int max = 0;
        for (int j = 1; j < N; j++)
            if (pq[max] < pq[j]) max = j;
        exch (pq[max], pq[N-1]);
        return pq[--N];
    }
};


