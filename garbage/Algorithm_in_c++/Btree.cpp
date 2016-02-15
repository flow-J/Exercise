template <typename Item, typename Key>
struct entry
{
    Key key;
    Item item;
    struct node *next;
};

struct node
{
    int m; entry<Item, Key> b[M];
    node() { m = 0; }
};

typedef node *link;

private:
    Item searchR(link h, Key v, int ht)
    {
        int j;
        if (ht == 0)
            for (j = 0; j < h->m; j++)
            {
                if (v == h->b[j].key)
                    return h->b[j].item;
            }
        else
            for (j = 0; j < h->m; j++)
                if ((j+1 == h->m) || (v < h->b[j+1].key))
                    return searchR(h->b[j].next, v, ht-1);
        return nullItem;
    }
    link insertR(link h, Item x, int ht)
    {
        int i, j; Key v = x.key();
        entry<Item, Key> t;
        t.key = v; t.item = x;
        if (ht == 0)
            for (j = 0; j < h->m; j++)
            {
                if (v < h->b[j].key)
                    break;
            }
        else
            for (j = 0; j < h->m; j++)
                if ((j+1 == h->m) || (v < h->b[j+1].key))
                {
                    link u;
                    u = insertR(h->b[j++].next, x, ht-1);
                    if (u == 0)
                        return 0;
                    t.key = u->b[0].key;
                    t.next = u;
                    break;
                }
        for (i = h->m; i > j; i--)
            h->b[i] = h->b[i-1];
        h->b[j] = t;
        if (++h->m < M)
            return 0;
        else
            return split(h);
    }
    link split(link h)
    {
        link t = new node();
        for (int j = 0; j < M/2; j++)
            t->b[j] = h->b[M/2+j];
        h->m = M/2; t->m = M/2;
        return t;
    }

public:
    ST(int maxN)
    {
        N = 0; HT = 0;
        head = new node;
    }
    Item search(Key v)
    {
        return searchR(head, v, HT);
    }
    void insert(Item item)
    {
        link u = insertR(head, item, HT);
        if (u == 0)
            return ;
        link t = new node(); t->m = 2;
        t->b[0].key = head->b[0].key;
        t->b[1].key = u->b[0].key;
        t->b[0].next = head; t->b[1].next = u;
        head = t; HT++;
    }
