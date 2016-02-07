#include <iostream>

struct node
{
    int item; node *next;
    node (int i, node* t)
        { item = i; next = t; }
};

typedef node* link;

auto create(input)
{
    link head = new node(1, NULL);
}
