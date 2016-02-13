template <typename Item, typename Key>
class ST
{
private:
    struct node
    {
        Item item; node *l, *r;
        node(Item x) { item = x; l = 0; r = 0; }
    };
    typedef node *link;
    link head;
    Item nullItem;
    Item searchR(link h, Key v)
    {
        if (h == 0)
            return nullItem;
        Key t = h->item.key();
        if ( v == t)
            return h->item;
        if (v < t)
            return searchR(h->l, v);
        else
            return searchR(h->r, v);
    }
    void insertR(link& h, Item x)
    {
        if (h == 0)
        { h = new node(x); return ; }
        if (x.key() < h->item.key())
            insertR(h->l, x);
        else
            insertR(h->r, x);
    }
    void insert(Item x)
    {
        Key v = x.key();
        if (head == 0)
        {
            head = new node(x); return ;
        }
        link p = head;
        for (link q = p; q != nullptr; p = q ? q : p)
        {
            q = (v < q->item.key()) ? q->l : q->r;
        }
        if (v < p->item.key())
            p->l = new node(x);
        else
            p->r = new node(x);
    }
public:
    ST(int maxN)
      { head = 0;}
    Item search(Key v)
      { return searchR(head, v); }
    void insert(Item x)
      { insertR(head, x); }
};
