int hash(char *v, int M)
{
    int h = 0, a = 127;
    for ( ; *v != 0; v++)
        h = (a*h + *v) % M;
    return h;
}

int hash(char *v, int M)
{
    int h, a = 31415, b = 27183;
    for (h = 0; *v != 0; v++, a = a*b % (M-1))
        h = (a*h + *v) % M;
    return (h < 0) ? (h + M) : h;
}
