#include <iostream>

struct node
{
    auto item, node *next;
    node(int x, node *t)
    { item = x; next = t; }
};

typedef node *link;

auto creat(int n)
{
    link t = new node(1, NULL); t->next = t;
    link x = t;
    for (int i = 0; i <= n; ++i)
        x = (x->next = new node (i, t));
}


