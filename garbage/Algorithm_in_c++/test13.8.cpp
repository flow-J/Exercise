template <typename Item>
class foo {
private:
    struct node
    {
        Item item; node **next; int sz;
        node(Item x, int k)
        {
            item = x; sz = k; next = new node*[k];
            for (int i = 0; i < k; i++)
                next[i] = 0;
        }
    };
    typedef node *link;
    link head;
    Item nullItem;
    int lgN;
public:
    ST(int)
    { head = new node(nullItem, lgNmax); lgN = 0; }
};
