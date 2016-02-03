#include <iostream>

node heada(0, NULL); link a = &heada, t = a;
for (int i = 0; i < N; i++)
    t = (t->next = new node(rand() % 1000, 0));

node headb(0, 0); link u, x, b = &headb;
for (t = a->next; t != 0; t = u)
{
    u = t->next;
    for (x = b; x->next != NULL; x = x->next)
        if (x->next->item > t->item) break;
    t->next = x->next; x-next = t;
}


