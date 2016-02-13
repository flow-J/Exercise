class
{
private:
    Item searchR(int l, int r, Key v)
    {
        if (l > r)
            return nullItem;
        int m = (l+r)/2;
        if (v == st[m].key()) return st[m];
        if (l == r) return nullItem;
        if (v < st[m].key())
            return searchR(l, m-1, v);
        else
            return searchR(m+1, r, v);
    }
public:
    Item search(Key v)
    { return searchR(0, N-1, v); }
};
