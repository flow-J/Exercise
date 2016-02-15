private:
    link* heads;
    int N, M;
public:
    ST(int maxN)
    {
        N = 0; M = maxN/5;
        heads = new link[M];
        for (int i = 0; i < M; i++)
            heads[i] = 0;
    }
    Item search(Key v)
    {
        return searchR()
    }
