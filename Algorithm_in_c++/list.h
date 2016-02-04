#ifndef c++_list_h
#define c++_list_h


class node
{
public:
    void construct(int);
    Node newNode(int);
    ~Node() { deleteNode(); }
    void insert(Node, Node);
    Node remove(Node);
    link remove(link x)
    { link t = x->next->next; return t;}
    Node next(Node);
    Item item(Node);
pirvate:
    link freelist;
    typedef node *link;
    typedef link Node;
    struct node { Item item; node *next; }
}

#endif


void construct(int N)
{
    freelist = new node[N+1];
    for (int i = 0; i < N; i++)
        freelist[i].next = &freelist[i+1];
    freelist[N].next = 0;
}

link newNode(int i)
{
    link x = remove(freelist);
    x->item = i; x->next = x;
    return x;
}

void deletNode(linx x)
{
    insert(freelist, x);
}
void insert(link x, link n)
{
    n->next = x->next; x->next = n;
}

link remove(link x)
{  link t = x->next->next; return t;}

link next(linx x)
{ return x->next; }
Item item(link x)
{ return x->item; }
