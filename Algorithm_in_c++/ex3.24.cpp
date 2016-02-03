#include <iostream>

struct node
{
    int item; node *next;
    auto node(int i, node *t)
        { item = x; next = t; }
};

typedef node *link;

auto creat(int n)
{
    link t = new node(1, NULL); t->next = t;
    link x = t;
    for (int i = 0; i <= n; ++i)
        x = (x->next = new node(i, t));
    return n;
}

int main()
{
    auto x = creat(20);
    for (link t = x; t != 0; t = t->next)

}
