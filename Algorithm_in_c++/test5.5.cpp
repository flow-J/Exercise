int count(link x)
{
    if (x == 0) return 0;
    return 1 + count(x->next);
}

void traverse(link h, void visit(link))
{
    if (h == 0) return ;
    visit(h);
    traverse(h->next, visit);
}

void traverseR(link h, void visit(link))
{
    if (h == 0) return ;
    traverserR(h->next, visit);
    visit(h);
}

void remove(link &x, Item v)
{
    while (x != 0 && x->item == v)
      {link t = x; x = x->next; delete t; }
    if (x != 0) remove(->next, v);
}
