#include <iostream>

class numbered {
public:
    numbered()
    {
        static int unique = 10;
        mysn = unique++;
    }

    numbered(const numbered& n) { mysn = n.mysn + 1; }

    int mysn;
};

void f(const numbered& s)
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
