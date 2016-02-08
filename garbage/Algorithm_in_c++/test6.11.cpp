#include <iostream>
#include <stdlib.h>
#include <string.h>

struct Item
{  char *str; }

static char buf[10000];
static int cnt = 0;
int operator<(const Item& a, const Item& b)
  { return strcmp(a.str, b.str) < 0; }

void show(const Item& x)
  { cout << x.str << " "; }

int scan(Item& x)
{
    int flag = (cin >> (x.str = &buf[cnt]) != 0);
    cnt += strlen(x.str)+1;
    return flag;
}

struct int Wrapper
{
    int item;
    intWrapper(int i = 0) { item = i; }
    operator int() const { return item; }
};
typedef intWrapper Index;
