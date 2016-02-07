#include <iostream>

using namespace std;

struct node
{
    int item; node *next;
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
    return x;
}

/*
auto getSize()
{

}*/

int main()
{
    auto x = creat(10);
    for (link t = x; t != NULL; t = t->next)
    {
        cout << t->item << " ";
    }
}
