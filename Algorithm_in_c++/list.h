#ifndef c++_list_h
#define c++_list_h


class node
{
public:
    void construct(int);
    void construct(int N)
    {
        freelist = new node[N+1];
        for (int i = 0; i < N; i++)
            freelist[i].next = &freelist[i+1];
        freelist[N].next = 0;
    }
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
