#include <stdlib.h>
template <typename Item, typename Key>
class ST
{
    private:
        Item nullItem;
        struct node
        {
            Item item; node* next;
            node(Item x, node* t) { item = x; next = t; }
        };
        typedef node *link;
        int N;
        link head;
        Item searchR(link t, Key v)
        {
            if (t == 0)
                return nullItem;
            if (t->item.key() == v)
                return t->item;
            return searchR(t->next, v);
        }
    public:
        ST(int maxN) { head = 0; N = 0; }
        int count() { return N; }
        Item search(Key v) { return searchR(head, v); }
        void insert(Item x) { head = new node(x, head); N++; }
};
