#include <iostream>

struct node
{
    Item item; node *l, *r;
    node (Item x) { item = x; l = 0; r = 0; }
};

typedef node* link;

link parse()
{
    char t = a[i++];
}
