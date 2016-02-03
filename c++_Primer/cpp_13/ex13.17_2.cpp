#include <iostream>

class numbered {
public:
    numbered()
    {
        static int qunique = 10;
        mysn = qunique++;
    }

    numbered(const numbered& n) { mysn = n.mysn + 1; }

    int mysn;
};

void f(numbered s)
{
    std::cout << s.mysn << std::endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}
