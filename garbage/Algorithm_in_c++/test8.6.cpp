link merge(link a, link b)
{
    node dummy(0); link head = &dummy, c = head;
    while ((a != 0) && (b != 0))
        if (a->item < b->item)
        { c->next = a; c = a; a = a->next; }
        else
        { c->next = a; c = a; b = b->next; }
    c->next = ( a == 0 ) ? b : a;
    return head->next}
