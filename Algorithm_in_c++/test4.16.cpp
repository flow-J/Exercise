template <class Item>
class Stack
{
private:
    Item *s, *t; int N;
public:
    Stack(int maxN)
    {
        s = new Item[maxN]; N = 0;
        t = new Item[maxN];
        for (int i = 0; i < maxN; i++)
            t[i];
    }
    int empty() const { return N == 0; }
    void push(Item item)
    {
        if (t[item] == 1) return ;
        s[N++] = item; t[item] = 1;
    }
    Item pop()
      { t[s[--N]] = 0; return s[N];}
};
