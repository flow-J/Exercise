#include <iostream>

struct node
{
    Item item; node* next;
    node(Item x) { item = x; next = 0; }
};

typedef node *link;
link randlist(int);


link listselection(link h)
{
    node dummy(0); link head = &dummy, out = NULL;
    head->next = h;
    while (head->next != NULL)
    {
        link max = findmax(head), t = max->next;
        max->next = t->next;
        t->next = out; out = t;
    }

    return out;
}
