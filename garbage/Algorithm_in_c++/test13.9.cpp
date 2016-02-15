int randX()
{
    int i, j, t = rand();
    for (i = 1, j = 2; i < lgNmax; i++, j+= j)
        if (t > RAND_MAX/j) break;
    if (i > lgN) lgN = i;
    return i;
}

void insertR(link t, link x, int k)
{
    Key v = x->item.key(); link tk = t->next[k];
    if ((tk == 0) || (v < tk->item.key()))
    {
        if (k < x->sz)
        {
            x->next[k] = tk;
            t->next[k] = x;
        }
        if (k == 0) return ;
        insertR(t, x, k-1);
        return ;
    }
    insertR(tk, x, k);
}


void insert(Item v)
{ insertR(head, new node(v, randX()), lgN); }
