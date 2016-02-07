void traverse(link h, void visit(link))
{
    if (h == 0) return ;
    visit(h);
    traverse(h->l, visit);
    traverse(h->r, visit);
}
